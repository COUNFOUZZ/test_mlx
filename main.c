#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int	i = 0;
	int j = 1080;

	int mid = 270;
	int midEnd = 810;
	while (i < 1080 && j > 0)
	{
		my_mlx_pixel_put(&img, i, i, 0x00C5FF);		// Cyan line
		my_mlx_pixel_put(&img, i, 0, 0xFFFFFF);		// White line
		my_mlx_pixel_put(&img, 0, i, 0x00FF0000);	// Red line
		my_mlx_pixel_put(&img, j, i, 0x1BFF00);		// Green line
		my_mlx_pixel_put(&img, 1079, i, 0xFFFF00);	// Yellow line
		my_mlx_pixel_put(&img, i, 1079, 0x9000EE);	// Purple line
		my_mlx_pixel_put(&img, i, 540, 0xFF65FA);	// Pink	line
		my_mlx_pixel_put(&img, 540, i, 0xEE9000);	// Orange line
		while (mid < midEnd)	// grey square
		{
			my_mlx_pixel_put(&img, mid, midEnd, 0x7B7B7B);	// grey line
			my_mlx_pixel_put(&img, midEnd, mid, 0x7B7B7B);	// grey line
			my_mlx_pixel_put(&img, mid, 270, 0x7B7B7B);		// grey line
			my_mlx_pixel_put(&img, 270, mid, 0x7B7B7B);		// grey line
			mid++;
		}
		i++;
		j--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

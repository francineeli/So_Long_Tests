#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int	handle_keypress(int keysym, t_data *data);

int	main(void)
{
    int i;
    int j;
    void *result;

	t_data	data;

    //Aqui inicializamos a conexão através da função mlx_init;
    //A função retorna um ponteiro que será o identificador da conexão, quer seja, mlx_ptr, já linkado a struct data
	data.mlx_ptr = mlx_init(); 
    //Aqui trabalhamos a possibilidade da conexão falhar e o ponteiro retornar NULO
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
    //Aqui abriremos a janela através da função mlx_new_window;
    //A função retorna um poteiro que será o identificar da janela, quer seja,  win_ptr, já linkado a struct data
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
    //Aqui trabalhamos a hipótese de erro e liberação da memória;
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
    result = mlx_xpm_file_to_image(data.mlx_ptr, "/Home/Images/Cat01.xpm", &i, &j);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, result, 100, 150);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}




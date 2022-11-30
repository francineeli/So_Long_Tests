typedef struct s_pointers {
    void    *mlx;
    void    *win;
    void    *img;
    void    *img2;
    int        img_w;
    int        img_w2;
    int        img_h;
    int        img_h2;
}    t_pointers;

typedef struct s_map {
    char    *name;
    int        fd;
    int        h;
    int        v;
}    t_map;

int    main(int argc, char **argv)
{
    t_pointers    ptrs;
    t_map        map;

    // game_start(ptrs, map);
    // mlx_put_image_to_window(ptrs.mlx, ptrs.win, ptrs.img, 400, 300);
    // mlx_loop(ptrs.mlx);
}
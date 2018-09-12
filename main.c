#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int bsq(int row, int column, int max_r, int max_c, char **map)
{
    int obstacle_found;
    int diagonal;
    int n;

    obstacle_found = 0;
    diagonal = 0;
    while (row + diagonal < max_r && column + diagonal < max_c)
    {
        n = 0;
        if (map[row + diagonal][column + diagonal] == 'o')
            break;
        diagonal++;
        while (n < diagonal && row + diagonal < max_r && column + diagonal < max_c)
        {
            if (map[row + diagonal][column + n] == 'o' ||
                map[row + n][column + diagonal] == 'o')
            {
                obstacle_found = 1;
                break;
            }
            n++;
        }
        if (obstacle_found)
            break;

    }
    return diagonal;
}

int *search_max(int res[3],int max_r, int max_c, char **map)
{
    int row;
    int diag;
    int column;

    row = 0;
    diag = 0;
    column = 0;

    while (row < max_r)
    {
        while (column < max_c)
        {
            //printf("%d",bsq(row, column, max_r, max_col, array));
            diag = bsq(row, column, max_r, max_c, map);
            if (diag > res[2])
            {
                res[0] = row;
                res[1] = column;
                res[2] = diag;
            }
            column++;
        }
        //printf("\n");
        column = 0;
        row++;
    }
    return (res);
}

void substitute(const int *res, int max_r, int max_c, char **map, char full)
{
    int row;
    int column;

    row = res[0];
    column = res[1];
    while (row < res[2] + res[0])
    {
        while (column < res[2] + res[1])
        {
        map[row][column] = full;
        column++;
        }
    column = res[1];
    row++;
    }
}

void show(int max_r, int max_col, char **map)
{
    int row;
    int column;

    row = 0;
    column = 0;
    while (row < max_r) {
        while (column < max_col) {
            printf("%c", map[row][column]);
            column++;
        }
        printf("\n");
        column = 0;
        row++;
    }
}

int main() {

//    char array[9][27] = {
//            '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','.','.','.','.','.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//            '.','.','.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.','.','.','.','o','.','.','.','.','.',
//            '.','.','o','.','.','.','.','.','.','.','o','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
//    };

    char array[3][3] = {
            '.','.','.',
            '.','.','.',
            '.','.','.',
    };

//    int res[3] = {0,0,0};
//    //int *search = search_max(res, 9, 27, array);
//    int *search = search_max(res, 3, 3, array);
//    res[0] = search[0];
//    res[1] = search[1];
//    res[2] = search[2];

//      char full = 'x';
//    substitute(res, 9,27,array, full);
//    show(9, 27, array);
//    substitute(res, 3,3,array, full);
//    show(3, 3, array);

    int fd = open("C:\\Users\\HumanAlone\\CLionProjects\\BSQ\\test2.txt", O_RDONLY);
    char buf[1024];
    int ret;
    ret = read(fd, buf, 1024);
//    while ((ret = read(fd, buf, 1024)) > 0)
//        write(1, buf, ret);

    int counter = 4;
//    printf("%c\n", buf[0]);
//    printf("%c\n", buf[1]);
//    printf("%c\n", buf[2]);
//    printf("%c\n", buf[3]);


    //map = (char*)malloc(sizeof(char) * (ret));
    int i = 0;
    int r =0;
    int col = 0;

//    char **map;
//    map = (char**)malloc(sizeof(char*) * 9);
//    while (i < 9)
//    {
//        map[i] = (char*)malloc(sizeof(char*) * 27);
//        i++;
//    }
    char **map;
    map = (char**)malloc(sizeof(char*) * 2);
    while (i < 2)
    {
        map[i] = (char*)malloc(sizeof(char*) * 2);
        i++;
    }
//char map[9][27];

    // Копируем из буфера в map
    while (r < 2)
    {
        while(col < 2)
        {
            //map[r][col] = buf[counter];
            //counter++;
            //col++;
            if (buf[counter] != '\n')
            {
                map[r][col] = buf[counter];
                counter++;
                col++;
            }
            else
                counter++;
        }
        col = 0;
        r++;
    }

//    int res[3] = {0,0,0};
//    int *search = search_max(res, 3, 3, array);
//    res[0] = search[0];
//    res[1] = search[1];
//    res[2] = search[2];
//    char full = 'x';
//    substitute(res, 3, 3, array, full);
//    show(3, 3, array);

    int res[3] = {0,0,0};
    int *search = search_max(res, 2, 2, map);
    res[0] = search[0];
    res[1] = search[1];
    res[2] = search[2];
    char full = 'x';
    substitute(res, 2, 2, map, full);
    show(2, 2, map);





//    while (buf[counter] != '\n')
//    {
//        //map[i] = buf[counter];
//        printf("%c", buf[counter]);
//        counter++;
//        //i++;
//        //map[i] = '\n';
//        //counter++;
//    }
    //map = buf;
//    while (*map++)
//    {
//        printf("%c", **map);
//    }
//    printf("\n%d\n", ret);
//    printf("%zd\n", sizeof(*buf));

    close(fd);


// вывести мэп
//    r = 0;
//    col = 0;
//    while (r < 9)
//    {
//        while(col < 27)
//        {
//            printf("%c", map[r][col]);
//            col++;
//        }
//        printf("\n");
//        col = 0;
//        r++;
//    }
//    printf("\n");

    return 0;
}

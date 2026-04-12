#include <stdio.h>
#include <string.h>

int main()
{
    while(1){
        int count = 1, n, tmp, top = 1, south = 2, east = 3;
        char str[6] = "";
        scanf("%d", &n);
        if(n == 0)return 0;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            switch(str[0]){
            case 'N':
                tmp = top;
                top = south;
                south = 7 - tmp;
                break;
            case 'E':
                tmp = east;
                east = top;
                top = 7 - tmp;
                break;
            case 'W':
                tmp = top;
                top = east;
                east = 7 - tmp;
                break;
            case 'S':
                tmp = south;
                south = top;
                top = 7 - tmp;
                break;
            case 'R':
                tmp = south;
                south = east;
                east = 7 - tmp;
                break;
            case 'L':
                tmp = east;
                east = south;
                south = 7 - tmp;
                break;
            }
            count += top;
        }
        printf("%d\n",count);
    }
}
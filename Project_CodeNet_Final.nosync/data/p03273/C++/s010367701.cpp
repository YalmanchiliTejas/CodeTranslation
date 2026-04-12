#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>
//#include <algorithm>
#include <vector>


int main(int argc, char* argv[])
{
    long h, w;
    scanf("%ld %ld", &h, &w);

    char str[100][100]={0};

    long i, j;
    for(i=0; i<h; i++) {
        scanf("%s", str[i]);
    }

    long skip[100]={0};
    for(i=0; i<w; i++) {
        for(j=0; j<h; j++){
            if(str[j][i]=='#')
                break;
        }
        if(j==h)
            skip[i]=1;
    }

    for(i=0; i<h; i++) {
        for(j=0; j<w; j++){
            if(str[i][j]=='#')
                break;
        }
        if(j==w) {
            continue;
        }

        for(j=0; j<w; j++){
            if(skip[j]==0) {
                char tmp[2]={0};
                tmp[0] = str[i][j];
                printf("%s", tmp);
            }
        }
        printf("\n");
    }

    //    printf("%d\n", a - b + 1);

    return 0;
}

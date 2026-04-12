#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int h,w;
    scanf("%d %d",&h,&w);
    char s[h][w+1];
    int i,j;
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    int r_c[h],l_c[w];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j] == '#'){
                r_c[i] = 1;
                break;

            }
            else if(j==w-1){//ここでindex iの行を取り除く
                r_c[i] = -1;
            }
        }
    }
    for(j=0;j<w;j++){
        for(i=0;i<h;i++){
            if(s[i][j] == '#'){
                l_c[j] = 1;
                break;
            }
            else if(i == h-1){
                l_c[j] = -1;
            }
        }
    }
    for(i=0;i<h;i++){
        if(r_c[i] == -1){
            continue;
        }
        for(j=0;j<w;j++){
            if(l_c[j] == -1){
                continue;
            }
            printf("%c",s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
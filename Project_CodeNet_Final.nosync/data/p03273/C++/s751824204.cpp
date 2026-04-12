#include <stdio.h>

int main(){

    int h,w;
    char a[100][103] = {{}};
    
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++){
        scanf("%s", &a[i]);
    }
    

    char ans[100][103] = {{}};
    char pre[100][103] = {{}};
    bool hit;
    int ii = 0;
    for (int i = 0; i < h; i++){
        hit = false;
        for (int j = 0; j < w; j++){
            if(a[i][j] == '#') break;
            if(j == w-1) {
                hit = true;
            }
        }
        if(!hit){
            for (int j = 0; j < w; j++){
                pre[ii][j] = a[i][j];
            }
            ii++;
        } 
    }
   /* printf ("\n");
    for (int i = 0; i < ii; i++){
        for (int j = 0; j < w; j++){
            printf ("%c", pre[i][j]);
        }
        printf ("\n");
    }
*/
   
    int jj = 0;
    for (int i = 0; i < w; i++){
        hit = false;
        for (int j = 0; j < ii; j++){
            if(pre[j][i] == '#') break;
            if(j == ii-1) {
                hit = true;
            }
        }
        if(!hit){
            for (int j = 0; j < ii; j++){
                ans[j][jj] = pre[j][i];
            }
            jj++;
        } 
    }
//    printf ("\n");
    for (int i = 0; i < ii; i++){
        for (int j = 0; j < jj; j++){
            printf ("%c", ans[i][j]);
        }
        printf ("\n");
    }

    return 0;

}
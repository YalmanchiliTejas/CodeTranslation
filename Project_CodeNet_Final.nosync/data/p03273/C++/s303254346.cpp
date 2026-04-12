/*ex7_3
 Sweet_Sweet_Soul */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int hei,wid;/*hei=height、wid＝width*/
    int *hei_ture,*wid_ture;/*各行や列に'#'があれば1を記録する配列*/
    char **grid;/*入力用の多次元配列*/
    scanf("%d%d",&hei,&wid);
    grid=(char**)calloc(hei,sizeof(char*));/*まず各配列の先頭のポインタを確保*/
    if(grid==NULL){
        exit(1);
    }
    for(int i=0;i<hei;i++){
        grid[i]=(char*)calloc(wid,sizeof(char));/*各配列の要素を確保*/
        if(grid[i]==NULL){
            exit(1);
        }
    }
    hei_ture=(int*)calloc(hei,sizeof(int));/*他二つのtrue配列も確保*/
    if(hei_ture==NULL){
        exit(1);
    }
    wid_ture=(int*)calloc(wid,sizeof(int));
    if(wid_ture==NULL){
        exit(1);
    }
    for(int i=0;i<hei;i++){
        for(int j=0;j<wid;j++){
            scanf(" %c",&grid[i][j]);/*gridに入力*/
            if(grid[i][j]=='#'){
                hei_ture[i]=1;/*ついでに真偽値も記録*/
                wid_ture[j]=1;
            }
        }
    }
    for(int i=0;i<hei;i++){
        if(hei_ture[i]==1){
            for(int j=0;j<wid;j++){
                if(wid_ture[j]==1){
                    printf("%c",grid[i][j]);/*行、列ともに真偽値1なら出力*/
                }
            }
            printf("\n");/*行ごとに改行*/
        }
    }
    /*先に各要素の配列のメモリを解放*/
    for(int i=0;i<hei;i++){
        free(grid[i]);
    }
    /*次に先頭のポインタを解放*/
    free(grid);
    free(hei_ture);
    free(wid_ture);
    return 0;
}

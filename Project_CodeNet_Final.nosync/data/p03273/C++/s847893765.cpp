#include<stdio.h>
int r[100];
int s[100];
int main(){
    char p[100][100];
    int H, W;
    scanf("%d%d", &H, &W);
    for(int i=0; i<H; i++){
            scanf("%s", &p[i]);       
            }
    for(int i=0; i<H; i++){
            int cnt = 0;
            for(int j=0; j<W; j++){
                    if(p[i][j]=='.'){
                                     cnt++;
                                     }
                    }
            if (cnt == W)
               r[i] = 0;
            else
               r[i] = 1;
    }
    for(int i=0; i<W; i++){
            int cnt = 0;
            for(int j=0; j<H; j++){
                    if(p[j][i]=='.'){
                                     cnt++;
                                     }
                    }
            if (cnt == H)
               s[i] = 0;
            else
               s[i] = 1;
    }

    for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                    if(s[j]==1 && r[i]==1){
                               printf("%c", p[i][j]);
                               }
                    }
            if(r[i]==1){
                        printf("\n");
                        }
            }
return 0;          
}

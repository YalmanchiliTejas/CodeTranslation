#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    char a[100][100];
    int row[100];
    int column[100];
    int counter = 0;

    scanf("%d%d",&H,&W);
    for(int i = 0;i <H;i++){
        counter = 0;
        for(int j = 0;j <W;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == '.'){
                counter++;
            }
        }
        if(counter == W){
            row[i] = 1;
        }else{
            row[i] = 0;
        }
    }
    for(int i = 0;i < W;i++){
        counter = 0;
        for(int j = 0;j < H;j++){
            if(a[j][i] == '.'){
                counter++;
            }
        }
        if(counter == H){
            column[i] = 1;
        }else{
            column[i] = 0;
        }
    }
    for(int i = 0;i < H;i++){
        if(row[i] == 1)continue;
        for(int j = 0;j<W;j++){
            if(column[j] == 1)continue;
            printf("%c",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

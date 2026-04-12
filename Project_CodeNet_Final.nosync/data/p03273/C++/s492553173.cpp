#include<bits/stdc++.h>
using namespace std;
char a[102][102], usedh[102], usedw[102];
int main(){
    int h, w;
    scanf("%d %d", &h, &w);
    for(int i = 1; i <= h; i++){
        scanf("%s", a[i] + 1);
    }
    for(int i = 1; i <= h; i++){
        bool flag = 0;
        for(int j = 1; j <= w; j++){
            if(a[i][j] == '#') flag = 1;
        }
        if(flag == 0){
            usedh[i] = 1;
        }
    }
    for(int j = 1; j <= w; j++){
        bool flag = 0;
        for(int i = 1; i <= h; i++){
            if(a[i][j] == '#') flag = 1;
        }
        if(flag == 0){
            usedw[j] = 1;
        }
    }
    for(int i = 1; i <= h; i++){
        if(usedh[i]) continue;
        for(int j = 1; j <= w; j++){
            if(usedw[j]) continue;
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}
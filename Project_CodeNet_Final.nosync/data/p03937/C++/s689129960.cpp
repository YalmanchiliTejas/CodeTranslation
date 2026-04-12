#include "bits/stdc++.h"
using namespace std;
const int N = 10;
int n , m;
char str[N][N];
char tmp[N][N];
void check(){
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(tmp[i][j] != str[i][j]){
                return;
            }
        }
    }
    printf("Possible\n");
    exit(0);
}
void go(int x , int y){
    tmp[x][y] = '#';
    if(x == n && y == m){
        check();
    }
    if(x < n){
        go(x + 1 , y);
    }
    if(y < m){
        go(x , y + 1);
    }
    tmp[x][y] = '.';
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str[i] + 1);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            tmp[i][j] = '.';
        }
    }
    go(1 , 1);
    printf("Impossible\n");
}
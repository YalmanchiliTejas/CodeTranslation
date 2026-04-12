#include <cstdio>
#include <cctype>
#include <cstdlib>
using namespace std;

void print(int n){
    int board[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    board[n/2+1][n/2] = 1;
    int x = n/2+2, y = n/2+1;
    for(int i = 2; i <= n*n; i++){
        while( true ){
            if( x >= n ){
                x = 0;
            }else if( y >= n ){
                y = 0;
            }else if( y < 0 ){
                y = n-1;
            }else if( board[x][y] ){
                x++;
                y--;
            }else{
                board[x][y] = i;
                break;
            }
        }
        x++;y++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%4d", board[i][j]);
        }
        puts("");
    }
}

int main(){
    int n;
    while( scanf("%d", &n), n ){
        print( n );
    }
    return 0;
}
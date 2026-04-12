#include <cstdio>
using namespace std;

void f(int a[][15], int n, int &x, int &y, int i)
{
    if(0 <= x && x < n && 0 <= y && y < n && a[x][y] == 0) {
        a[x][y] = i;
        x++; y++;
        return;
    }
    
    if(x < 0){
        x = n-1;
    }
    if(n <= x){
        x = 0;
    }
     if(y < 0){
        y = n-1;
    }
    if(n <= y){
        y = 0;
    }
    
    if(a[x][y] != 0){
        x--;
        y++;
    }
    
    f(a, n, x, y, i);
}

int main()
{
    int n;
    while(scanf("%d", &n), n){
        int a[15][15] = {};
        
        int x = n / 2, y = n / 2 + 1;
        a[x][y] = 1;
        x++; y++;
        for(int i = 2; i <= n * n; ++i){
            f(a, n, x, y, i);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%4d", a[j][i]);
            }
            puts("");
        }
    }
}
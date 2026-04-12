// Created by sz
#include<bits/stdc++.h>
using namespace std;

__int128 total_level[55];
__int128 total_party[55];

void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    getchar();
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}

void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}

__int128 solve(int N, __int128 X){
    if(N == 1){
        if(X == 0) return 0;
        if(X == 1) return 0;
        if(X == 2) return 1;
        if(X == 3) return 2;
        if(X == 4) return 3;
        if(X == 5) return 3;
    }
    if(X == total_level[N-1]+2) return total_party[N-1]+1;
    if(X ==  total_level[N-1] +1) return total_party[N-1];
    if(X == total_level[N] || X == total_level[N] - 1) return total_party[N];
    if(X < total_level[N-1]+1){
        return solve(N-1, X-1);
    }
    if(X > total_level[N-1]+2){
        return solve(N-1, X - total_level[N-1] -2 ) +1 + total_party[N-1];
    }
    
    
}

int main() {
//    freopen("./input.txt", "r", stdin);
    int N;
    __int128 X, ans;
    scanf("%d", &N);
    scan(X);
    
    total_level[1] = 5;
    total_party[1] = 3;
    for(int i= 2; i <= N; i++){
        total_level[i] = total_level[i-1]*2 + 3;
        total_party[i] = total_party[i-1]*2 + 1;
    }
    
    ans = solve(N,X);
    print(ans);
    printf("\n");
    return 0;
}


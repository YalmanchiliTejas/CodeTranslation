#include <bits/stdc++.h>

const int N = 1e5 + 10;

long long n, x, m;
int bo[N];
long long b[N];
long long sum[N];
int top=0;
int main() {
    std::cin >> n >> x >> m;
    x = x % m;
    for (int i = 1; i <= m+1&&i<=n; ++i) {
        if (bo[x]>0) {        
            break;
        }
        b[++top]=x;
        sum[top]=sum[top-1]+x;
        bo[x] = i;
        x = x * x%m;
    }
    if(n>top){
        std::cout<<sum[top]+(n-top)/(top-bo[x]+1)*(sum[top]-sum[bo[x]-1])+sum[(n-top)%(top-bo[x]+1)+bo[x]-1]-sum[bo[x]-1];
    }else{
        std::cout<<sum[top]<<'\n';
    }
    return 0;
}
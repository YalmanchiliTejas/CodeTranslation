#include <bits/stdc++.h>
using namespace std;

int vis[100005];
long long sum[100005];
int main(){
    long long n, x, m;
    scanf("%lld%lld%lld", &n, &x, &m);
    if(x == 0) printf("0\n");        
    else{

        long long y = x;
        int i = 1;
        long long temp = x;
        vis[y] = 1;
        sum[y] = x;

        long long ans = x;
        n--;
        while(n > 0){
            i++;
            y = y*y%m;
            temp += y;
            ans += y;
            n--;

            if(vis[y] && n >= i-vis[y]){
                int d = i-vis[y];
                ans += (temp - sum[y])*(n/d);
                n %= d;
            }

            vis[y] = i;
            sum[y] = temp;
        }

        printf("%lld\n", ans);


    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0;
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=m+1;i<=n;i++){
        long long mok = n / i;
        ans += mok * (i - m);
        if((n%i) >= m){
            ans += (n%i) - m + 1;
        }
    }
    if(m == 0) ans -= n;
    printf("%lld\n", ans);
}

/*

fix the b.
n = pb + r (0 <= r < b)
    a%b : 0,1,...,b-1,0,1,...,b-1(that appears for p times),0,1,...,r
    then , cnt += p*(max(0,b-k)) + max(0,r-k+1)

*/

//code by lynmisakura.wish to be accepted!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll n,k;scanf("%lld %lld",&n,&k);
    ll ans = 0;
    for(ll b = 1;b <= n;b++){
        ll p = n / b,r = n % b;
        ans += p*max(0LL,b-k) + max(0LL,r-k+1);
    }
    if(k == 0){
        ans -= n;
    }
    printf("%lld\n",ans);
}

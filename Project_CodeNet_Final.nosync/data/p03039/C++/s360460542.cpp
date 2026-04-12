#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);
ll modpow(ll a,ll b){
    ll ret = 1;
    while(b>0){
        if(b&1)ret = (ret*a)%MOD;
        a = (a*a)%MOD;
        b = b>>1;
    }
    return ret;
}

ll combmod(ll n,ll r){
    ll nn = 1;
    ll rr = 1;
//    if(n-r<r){
//        r=n-r;
//    }
    rep(i,r){
        nn *= (n-i);
        nn %=MOD;
        rr *= (r-i);
        rr %=MOD;
    }
    return nn*modpow(rr,MOD-2)%MOD;

}
int main() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans1 = 0;
    ll ans2 = 0;
    ll nm2 = (n*m)-2;
    nm2%=MOD;
    nm2 = combmod(nm2,(k-2));


    for(int i=0;i<n;i++){
        ll a = (n-i)*(i);
        a%=MOD;
        a*=(m*m)%MOD;
        a%=MOD;
        a *= nm2;
        a%=MOD;
        ans1 +=a;
        ans1%=MOD;
    }
   // cout<<ans1<<endl;

    for(int i=0;m-i>0;i++){
        ll a = (m-i)*(i);
        a%=MOD;
        a*=(n*n)%MOD;
        a%=MOD;
        a *= nm2;
        a%=MOD;
        ans2 += a;
        ans2%=MOD;
    }
    //cout<<ans2<<endl;
    cout<<(ans1+ans2)%MOD<<endl;







    return 0;
}

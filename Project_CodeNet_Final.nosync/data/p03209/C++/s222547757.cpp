#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;


ll func(ll n, ll x){
    if(n == 0)return 1;

    ll len = (1LL<<(n+1)) - 3;
    ll p = (1LL<<n) - 1;

    if(x == 1)return 0;
    else if(x <= len + 1)return func(n-1, x-1);
    else if(x == len + 2)return p + 1;
    else if(x <= 2*len + 2)return p + 1 + func(n-1, x - len - 2);
    else return 2*p + 1;
}

int main(){
    ll n, x;
    cin >> n >> x;

    cout << func(n, x) << endl;
}
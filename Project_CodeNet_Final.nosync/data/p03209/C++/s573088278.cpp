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

vector<ll> a(55), p(55);

ll func(ll n, ll x){
    if(x == 1){
        if(n == 0)return 1;
        else return 0;
    }
    else if(x <= a[n-1] + 1)return func(n-1, x-1);
    else if(x == a[n-1] + 2)return p[n-1] + 1;
    else if(x <= 2*a[n-1] + 2)return p[n-1] + 1 + func(n-1, x - (a[n-1] + 2));
    else return 2*p[n-1] + 1;
}

int main(){
    ll n, x;
    cin >> n >> x;

    a[0] = 1, p[0] = 1;
    rep(i, 50){
        a[i+1] = 2*a[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }

    cout << func(n, x) << endl;
}
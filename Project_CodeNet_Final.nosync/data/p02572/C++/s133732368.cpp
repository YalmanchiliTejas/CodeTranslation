#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll modpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % inf;
        y >>= 1;
        x = 1LL * x * x % inf;
    }
    return res;
}

int main(){cout<<fixed<<setprecision(20);
		   ll n;
           cin>>n;
           vll a(n);
           rep(i,0,n)cin>>a[i];
           ll sum=0;
           rep(i,0,n)
           {
            sum+=a[i];
             sum%=inf;
           }
           ll ans=0;
           rep(i,0,n){
            ll k= sum-a[i];
             if(k<0)k+=inf;
            ans+=k*a[i];
             ans%=inf;
           }
           ans=ans*modpow(2,inf-2)%inf;
           cout<<ans<<endl;
}
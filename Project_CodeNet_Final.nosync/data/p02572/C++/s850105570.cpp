#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl;

#define sz(x) (int)(x).size()
#define HOGE cout << "hoge" << endl;
using P = pair<ll,ll>;

template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}

const int INF = 1e9;
const ll m = 1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    ll sum = 0;
    REP(i,n){
      	sum += a[i];
      	sum %= m;
    }
    ll ans;
    ans = sum*sum;
    ans %= m;
    REP(i,n){
        ans -= (a[i]*a[i])%m;
      	while(ans<0) ans += m;
        ans %= m;
    }
    if(ans%2==0) cout << ans/2 << endl;
    else cout << (ans+m)/2 << endl;
}

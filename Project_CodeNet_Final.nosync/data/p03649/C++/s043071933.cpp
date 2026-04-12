#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//exist x map o setconst ll MOD = 1e9+7;return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> a(n);
    ll t=0;
    rep(i,n){
        cin >> a[i];
        t+=a[i];
    }
    t-=(n*(n-1));
    chmax(t,0);
    while(1){ //t kai
        vector<ll> v(n);
        rep(i,n) v[i]=a[i]+t;
        ll cnt=0;
        rep(i,n){
            if(v[i]>n-1LL){
                cnt+=((v[i]+1LL)/(n+1));
            }
        }
        if(cnt<=t){
            cout << t << endl;
            return 0;
        }
        t++;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <unistd.h>
#define inf 1000000007LL
#define INF 1000000000000000007LL
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define st first
#define nd second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define LOG(x) (63-__builtin_clzll(x))
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i, n) for(int i=1; i<=(n); ++i)
#define endr cerr<<'\n'
#define endl '\n'
#ifdef DEBUG
#define pv(...) cerr<<'\n',dbg(#__VA_ARGS__, __VA_ARGS__)
#define ps(x) {cerr<<'\n'<<#x<<":\n:";for(auto _q:(x)){cerr<<_q<<" ";}cerr<<'\n';}
#define pa(x, xs) {cerr<<'\n'<<#x<<":\n:";for(int _q=0; _q<=(xs); ++_q){cerr<<x[_q]<<" ";}cerr<<'\n';}
#define pal(x, xs) {cerr<<'\n'<<#x<<":\n";for(int _q=0; _q<=(xs); ++_q){cerr<<_q<<": "<<setw(_q? 3-(int32_t)log10(_q):3)<<x[_q]<<'\n';}cerr<<'\n';}
#define ppii(x, xs) {cerr<<'\n'<<#x<<":\n";for(int _q=0; _q<=(xs); ++_q){cerr<<_q<<": "<<setw(_q? 6-(int32_t)log10(_q):6)<<x[_q].first<<" "<<setw(5)<<x[_q].second<<'\n';}cerr<<'\n';}
#define pm(x, xn, xm) {cerr<<'\n'<<#x<<":\n";for(int _qa=0; _qa<=(xn); ++_qa){for(int _qb=0; _qb<=(xm); ++_qb){cerr<<setw(6)<<x[_qa][_qb]<<" ";}cerr<<'\n';}cerr<<'\n';}
#else
#define cerr if(0)cout
#define pv(...) if(0)endr
#define ps(x) if(0)endr
#define pa(x, xs) if(0)endr
#define pal(x, xs) if(0)endr
#define ppii(x, xs) if(0)endr
#define pm(x, xn, xm) if(0)endr
#endif
using namespace std;
template<class T> void dbg(const char* xn, T x){cerr<<xn<<": "<<x<<"\n";} template<class T, class... TA> void dbg(const char* xn, T x, TA... t){while(*xn!=',')cerr<<*xn++;cerr<<": "<<x<<",";dbg(xn+1, t...);}
template<class T> inline bool upd_max(T &x, T y){return y>x?x=y,true:false;} template<class T> inline bool upd_min(T &x, T y){return y<x?x=y,true:false;}
const int N = 1000007;
#define int long long

int n, k, rst = 0;


void solve()
{
  cin>>n>>k;

  for (int a=1; a<=n; ++a)
  {
    int res = 0;
    int whole = n/a;
    res += max(0LL, whole*(a-1-k+1));
    int rest = n - whole*a;
    res += max(0LL, rest-k+1);

    rst += res;
  }

  if (k == 0) rst -= n;
  cout<<rst;
}

int32_t main()
{
ios_base::sync_with_stdio(0); cin.tie(0);
cout<<fixed<<setprecision(10);

  solve();

return 0;
}

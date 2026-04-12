#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
using Int = long long;
typedef pair<int,int> Pi; typedef pair<Int,Int> Pl;
constexpr int mod = 1e9+7;
constexpr int INF32 = numeric_limits<int>::max();
constexpr Int INF64 = numeric_limits<Int>::max();
#define END {cout<<ans<<'\n'; return 0;}
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define Pr(t) priority_queue<t>
#define gPr(t) priority_queue<t,vector<t>,greater<t>>
#define V(t) vector<t>
#define rer(i,l,r) for(int i=(l); i<(r); ++i)
#define rep(i,n) rer(i,0,n)
#define gnr(i,l,r) for(int i=(r)-1; i>=(l); --i)
#define pri(a) cout<<(a)<<'\n'
#define pri2(a,n) {rep(i,n-1)cout<<a[i]<<' '; if(n)cout<<a[n-1]<<'\n';}
#define prip(p) cout<<(p).fi<<' '<<(p).se<<'\n'
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

Int n,m,_,x,y,q;
string s,sb;
bool ok;
char cf,cb;

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  cin>>n; V(int)ans(26,100);
  rep(i,n){
    cin>>s; V(int)cnt(26,0);
    for(char c:s)cnt[c-'a']++;
    rep(j,26)cmin(ans[j],cnt[j]);
  }
  rep(i,26){
    rep(j,ans[i])cout<<char('a'+i);
  }
  cout<<'\n';
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
#define vector2(a,b,c) vector<vector<int>> a(b/*縦！w*/,vector<int>(c/*横！w*/))
#define INF 1e10
#define MOD 1e9+7
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
signed main(){
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int f=min(d,e);
  int h=max(d,e);
  int g=0;
  if(a+b<=2*c)
    g+=(a+b)*f;
    else
      g+=c*2*f;
  int k;
  if(h==d)
    k=a;
  else
    k=b;
  if(k<c*2)
    g+=k*(h-f);
  else
    g+=c*2*(h-f);
  cout<<g<<endl;
}
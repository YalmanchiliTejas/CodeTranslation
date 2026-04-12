#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define INF 1 << 30
#define LLINF 1LL << 60
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define FORALL(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FOREACH(i,c) for(auto (i) : (c))
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
typedef complex<double> dcomplex;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cout<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}

int main()
{
  int n;
  while(cin>>n,n)
  {
    vector<vector<int> > T(n,vector<int>(n,0));
    int k=1, x=n/2+1, y=n/2;
    while(k<=n*n)
    {
      while(T[x][y]!=0)
      {
        x = (x+1)%n;
        y = (y-1)%n;
        y = y<0? y+n : y;
      }
      T[x][y] = k;
      x = (x+1)%n;
      y = (y+1)%n;
      k++;
    }
    REP(i,n){REP(j,n) printf("%4d",T[i][j]); printf("\n");}
  }
  return 0;
}
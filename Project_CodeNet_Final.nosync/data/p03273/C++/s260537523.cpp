#include<bits/stdc++.h>
#define rep(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define all(x) (x).begin(),(x).end()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
const ll MOD = (1e+9)+7;
typedef pair<ll, ll> LP;
ll POW(ll m,ll n)
{
  if(n<0) return 0;
  if(n==0) return 1;
  return m*POW(m,n-1);
}
 
int main()
{
  int h,w,k;
  char a[200][200];
  k=0;
  cin >> h >> w;
  rep(i,h){
    rep(j,w){cin >> a[i][j];
            }
  }
  rep(i,h){
    rep(j,w){if(a[i][j]=='#'){a[i][w]='#';
                              a[h][j]='#';
                             }
            }
  }
  rep(i,h){
    rep(j,w){if(a[i][w]=='#'&&a[h][j]=='#'){if(k==0)printf("\n");
                                            printf("%c",a[i][j]);
                                            k=5;
                                           }
            }k=0;
  }
}
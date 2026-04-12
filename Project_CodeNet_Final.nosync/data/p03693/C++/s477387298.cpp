#include<bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,n) for(int i=1; i<(n); i++)
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define int long long
#define setout(n,x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10)
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000007;
using namespace std;
long long h[10000010],x[10000010];

signed main(){
      
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r,g,b;
  cin>>r>>g>>b;

  r=r*100+g*10+b;
  if(r%4==0) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';
}


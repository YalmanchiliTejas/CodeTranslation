#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

int a,b,c,x,y;

int main(){
  cin >> a >> b >> c >> x >> y;
  int n=a*x+b*y;;
  int ans=n;
  int z= max(x,y);
  bitset<2> pat;
  reps(i,2*z){
    if(x<=0) pat.set(0);
    if(y<=0) pat.set(1);
    int k;
    if(pat==0)
      k=n+2*c-a-b;
    if(pat==1)
      k=n+2*c-b;
    if(pat==2)
      k=n+2*c-a;
    if(pat==3)
      k=n+2*c;
    ans=min(ans,k);
    n=k;
    x--;y--;
  }
  cout << ans;
}
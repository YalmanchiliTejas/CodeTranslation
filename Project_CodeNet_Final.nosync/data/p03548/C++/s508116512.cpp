#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define fs first
#define sc second
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=1;
  rep(i,100000) if(y*i+z*(i+1)<=x)ans=max(ans,i); else break;
  cout<<ans<<endl;
}
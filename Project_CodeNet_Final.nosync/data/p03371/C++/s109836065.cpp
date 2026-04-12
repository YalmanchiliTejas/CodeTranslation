#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll s1,s2,s3;
  s1=a*x+b*y;
  if(x>=y){
    s2=c*y*2+a*(x-y);
  }
  if(x<y){
    s2=c*x*2+b*(y-x);
  }
  s3=c*max(x,y)*2;
  ll ans=min(s1,min(s2,s3));
  cout<<ans<<endl;
}
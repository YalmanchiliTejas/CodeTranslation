#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=2e9;
  for(int i=0;i<=2*max(x,y);i+=2){
    ans=min(ans,i*c+max(0,(x-i/2))*a+max(0,(y-i/2))*b);
  }
  cout<<ans<<endl;
}
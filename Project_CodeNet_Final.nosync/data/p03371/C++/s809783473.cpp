#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans=a*x+b*y;

  reps(i,max(x,y)+1){
    ll tmp=2*i*c+a*max(0LL,x-i)+b*max(0LL,y-i);
    ans=min(ans,tmp);
  }


  cout<<ans<<endl;
  return 0;
}

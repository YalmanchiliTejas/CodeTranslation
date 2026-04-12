#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=61
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)

int main() {
  ll a,b,ab,x,y=0;
  ll ans=0;
  cin>>a>>b>>ab>>x>>y;
  if(a+b<=ab*2){
    ans=x*a+y*b;cerr<<1;
  }
  else{
    ans=2*ab*min(x,y);
    if(x<=y){
      
      ans+=(y-x)*b;cerr<<ans;
    }
    else
    {
      ans+=(x-y)*a;cerr<<22;
    }
    
  }cerr<<y;
  ans=min(ans,max(y,x)*ab*2);
  cout<<ans<<endl;
}
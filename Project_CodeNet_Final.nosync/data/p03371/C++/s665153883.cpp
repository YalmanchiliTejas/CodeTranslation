//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> >vvi;
const ll MOD=1000000007LL;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans;
  if(a+b>=2*c){
    if(x>y){
      if(2*c<a)ans=x*2*c;
      else ans=y*2*c+(x-y)*a;
    }
    else{
      swap(x,y);
      swap(a,b);
      if(2*c<a)ans=x*2*c;
      else ans=y*2*c+(x-y)*a;
    }
    cout<<ans<<endl;
    return 0;
  }
  else cout<<x*a+b*y<<endl;
}
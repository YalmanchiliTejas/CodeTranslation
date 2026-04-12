#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define cin()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans;
  if(a+b<2*c){
    ans = a*x + b*y;
  }else{
    ans = 2*c*min(x,y);
    if(x>y){
      if(a<2*c) ans+=a*(x-y);
      else ans+=2*c*(x-y);
    }else{
      if(b<2*c) ans+=b*(y-x);
      else ans+=2*c*(y-x);
    }
  }

  puts(ans);
}
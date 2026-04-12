#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll min_ans=100100100100;
  rep(i,100010){
    ll ans;
    ans=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
    min_ans=min(min_ans,ans);
  }
  cout<<min_ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  int ans=10e9;
  for (int i=0; i<=max(x,y)*2; i+=2){
    int t_ans=0;
    t_ans+=max(a*(x-i/2),0);
    t_ans+=max(b*(y-i/2),0);
    t_ans+=c*i;
    ans=min(ans,t_ans);
  }
  cout<<ans<<endl;
}
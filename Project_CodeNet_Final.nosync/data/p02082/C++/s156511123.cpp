#include <bits/stdc++.h>
using namespace std;

signed main(){
  int s,t,p,q,M,y;cin>>s>>t>>p>>q>>M>>y;
  /*
  int now=y,pre=0;
  for(int i=1;i<=1e8;i++){
    int a=pre*p+q;a%=M;
    now^=a;pre=a;
  }
  cout<<now<<endl;
  */
  cout<<(t^s^y)<<endl;
}


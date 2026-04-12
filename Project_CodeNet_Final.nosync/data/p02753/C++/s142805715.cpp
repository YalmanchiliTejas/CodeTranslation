#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  int n,a=0,b=0;
  string s;
  cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]=='A'){
      a++;
    }else if(s[i]=='B'){
      b++;
    }
  }
  if(a>0 && b>0){
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
}

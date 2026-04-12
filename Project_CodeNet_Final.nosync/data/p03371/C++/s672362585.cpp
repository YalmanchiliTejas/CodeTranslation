#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=a*x+b*y;
  int an=x;
  int bn=y;
  for(int i=1;i<=max(x,y)*2;i++){
    int tmp=ans+2*c;
    if(an>0){
      tmp-=a;
      --an;
    }
    if(bn>0){
      tmp-=b;
      --bn;
    }
    if(tmp<ans){
      ans=tmp;
    }else{
      break;
    }
    if(an==0&&bn==0){
      break;
    }
  }
  cout<<ans<<endl;


}
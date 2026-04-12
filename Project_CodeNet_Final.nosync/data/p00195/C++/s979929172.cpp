#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

main(){
  int ans,t,a,b;
  while(cin>>a>>b){
    if ( a == 0 && b == 0)break;
    ans=a+b;
    t=0;
    REP(i,1,5){
      cin>>a>>b;
      if ( a+b>ans){ans=a+b;t=i;}
    }
    cout << (char)(t+'A')<<" " << ans << endl;
  }
}
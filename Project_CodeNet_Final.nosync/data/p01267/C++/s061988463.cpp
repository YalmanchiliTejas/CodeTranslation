#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,x,y[100];
  while(cin>>n>>a>>b>>c>>x, n){
    for(int i=0;i<n;++i) cin>>y[i];
    int ans=-1, cnt=0;
    for(int i=0, j=0;i<10001;++i, x=(a*x+b)%c)
      if(x==y[j]){
        cnt++, j++;
        if(cnt==n){
          ans=i;
          break;
        }
      }
    cout<<ans<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
#define INF (1<<28)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long
signed main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int a[100010],stat=0;
  lp(z,4){
    if(z==0){
      a[0]=0;
      a[1]=0;
    }
    if(z==1){
      a[0]=0;
      a[1]=1;
    }
    if(z==2){
      a[0]=1;
      a[1]=0;
    }
    if(z==3){
      a[0]=1;
      a[1]=1;
    }
    int target;
    lp(i,n+1){
      if(i==0) {
        if(a[i]==0){
          if(s[i]=='o'){
            target=a[i+1];
          }
          else{
            target=abs(a[i+1]-1);
          }
        }
        else{
          if(s[i]=='x'){
            target=a[i+1];
          }
          else{
            target=abs(a[i+1]-1);
          }
        }
      }
      else{
        if(a[i]==0){
          if(s[i]=='o'){
            a[i+1]=a[i-1];
          }
          else{
            a[i+1]=abs(a[i-1]-1);
          }
        }
        else{
          if(s[i]=='x'){
            a[i+1]=a[i-1];
          }
          else{
            a[i+1]=abs(a[i-1]-1);
          }
        }
      }
    }
    if(a[n-1]==target&&a[n]==a[0]){
      stat=1;
      break;
    }
  }
  if(stat==0) cout<<-1<<endl;
  else{
    lp(i,n){
      if(a[i]==0) cout<<"S";
      else cout<<"W";
    }
    cout<<endl;
  }
  return 0;
}
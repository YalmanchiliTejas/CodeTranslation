#include"bits/stdc++.h"
using namespace std;

#define int long long

int n,arr[200005],ps[200005];

void main2(){
  int sum2=0,ans;
  for(int x=0;x<n;x++){
    if((x%2)==1)sum2+=arr[x];
  }
  ans=sum2;
  for(int x=0;x<n;x+=2){
    sum2+=arr[x]-arr[x+1];
    ans=max(ans,sum2);
  }
  cout<<ans<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int sum=0,ans=LLONG_MIN,maxi=LLONG_MIN;
    cin>>n;
    for(int x=0;x<n;x++){
      cin>>arr[x];
    }
    if((n%2)==0){
      main2();
      return 0;
    }
    for(int x=0;x<n;x+=2){
      if((x%2)==0){//odd elements...
        sum+=arr[x];
      }
    }
    ps[0]=0;
    for(int x=0;x<n;x++){
      ps[x+1]=ps[x];
      if((x%2)==1){//even elements...
        ps[x+1]+=arr[x]-arr[x+1];
      }
    }
    for(int x=n;x>=1;x-=2){//try removing every element...
      maxi=max(maxi,ps[x]);
      ans=max(ans,sum+maxi-ps[x]-arr[x-1]);
    }
    cout<<ans<<'\n';
    return 0;
}
/*

*/

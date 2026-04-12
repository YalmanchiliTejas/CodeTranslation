//29
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  for(int n,m;cin>>n>>m,n|m;){
    int t[20001]={};
    for(int i=0;i<n+m;i++){
      cin>>t[i+1];
    }
    sort(t,t+n+m+1);
    int mi=0;
    for(int i=1;i<n+m+1;i++){
      mi=max(mi,t[i]-t[i-1]);
    }
    cout<<mi<<endl;
  }
  return 0;
}
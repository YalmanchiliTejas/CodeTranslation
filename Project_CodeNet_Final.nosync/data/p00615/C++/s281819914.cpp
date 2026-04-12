#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 20000
int t[MAX],n,m,ans;
int main(){
  while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<m;i++)cin>>t[i+n];
    sort(t,t+n+m);
    ans=t[0];
    for(int i=1;i<n+m;i++)ans=max(ans,t[i]-t[i-1]);
    cout<<ans<<endl;
  }
  return 0;
}
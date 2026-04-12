#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,q;
  cin>>n>>q;
  int c[n+2];
  memset(c,0,sizeof(c));
  int p=1;
  c[p]=2;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    c[p-1]=1;
    c[p+1]=1;
    if(p==a) p=b;
    else if(p==b) p=a;
    swap(c[a],c[b]);
    c[p-1]=1;
    c[p+1]=1;
  }
  int ans=0;
  for(int i=1;i<=n;i++) ans+=c[i];
  cout<<ans-1<<endl;
  return 0;
}

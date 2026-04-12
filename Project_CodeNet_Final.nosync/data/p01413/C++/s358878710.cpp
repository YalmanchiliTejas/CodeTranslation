#include<bits/stdc++.h>
using namespace std;
#define int long long
int V[1<<10],C[1<<10];
int T[11111];
int n,m,w,t;
int l[10],x[10],y[10];
void dfs(int u,int b,int d){
  if(C[b]<0) C[b]=d+abs(x[u])+abs(y[u]);
  C[b]=min(C[b],d+abs(x[u])+abs(y[u]));
  for(int i=0;i<n;i++){
    if((b>>i)&1) continue;
    dfs(i,b+(1<<i),d+abs(x[u]-x[i])+abs(y[u]-y[i]));
  }
}
signed main(){
  cin>>n>>m>>w>>t;
  string s[m];
  int v[m],p[m];
  for(int i=0;i<m;i++) cin>>s[i]>>v[i]>>p[i];
  string r[10][10];
  int q[10][10];
  for(int i=0;i<n;i++){
    cin>>l[i]>>x[i]>>y[i];
    for(int j=0;j<l[i];j++) cin>>r[i][j]>>q[i][j];
  }
  map<string,int> msi;
  for(int i=0;i<m;i++) msi[s[i]]=i;
  memset(V,0,sizeof(V));
  for(int b=0;b<(1<<n);b++){
    memset(T,-1,sizeof(T));
    T[0]=0;
    for(int i=0;i<n;i++){
      if(!((b>>i)&1)) continue;
      for(int j=0;j<l[i];j++){
	int W=v[msi[r[i][j]]],D=p[msi[r[i][j]]]-q[i][j];
	if(D<=0) continue;
	for(int k=0;k<=w;k++){
	  if(T[k]<0) continue;
	  if(k+W>w) continue;
	  T[k+W]=max(T[k+W],T[k]+D);
	}
      }
    }
    for(int i=0;i<=w;i++) V[b]=max(V[b],T[i]);
  }
  memset(C,-1,sizeof(C));
  C[0]=0;
  for(int i=0;i<n;i++) dfs(i,1<<i,abs(x[i])+abs(y[i]));
  memset(T,-1,sizeof(T));
  T[0]=0;
  for(int b=0;b<(1<<n);b++){
    //cout<<b<<" "<<V[b]<<" "<<C[b]<<endl;
    if(V[b]<=0) continue;
    for(int k=0;k<=t;k++){
      if(T[k]<0) continue;
      if(k+C[b]>t) continue;
      T[k+C[b]]=max(T[k+C[b]],T[k]+V[b]);
    }
  }
  int ans=0;
  for(int i=0;i<=t;i++) ans=max(ans,T[i]);
  cout<<ans<<endl;
  return 0;
}
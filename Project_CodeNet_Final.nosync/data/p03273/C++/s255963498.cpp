#include<bits/stdc++.h>
using namespace std;
int a[110][110],h[110],w[110];
int main(){
  int m,n;
  char c;
  memset(a,0,sizeof(a));
  memset(h,0,sizeof(h));
  memset(w,0,sizeof(w));
  cin>>m>>n;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
      cin>>c;
      if(c=='\n')cin>>c;
      if(c=='#')h[i]=1,w[j]=1,a[i][j]=1;
      else a[i][j]=0;
    }
  for(int i=0;i<m;i++){
    if(!h[i])continue;
    for(int j=0;j<n;j++){
      if(!w[j])continue;
      if(a[i][j])cout<<'#';
      else cout<<'.';
    }
    cout<<'\n';
  }
  return 0;
}
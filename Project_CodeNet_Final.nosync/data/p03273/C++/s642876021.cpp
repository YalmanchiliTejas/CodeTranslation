#include <bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  int h,w;
  cin>>h>>w;
  int a[h]={},b[w]={};
  string s[h];
  r(i,h)cin>>s[i];
  r(i,h){
    int S=0;
    r(j,w)if(s[i][j]=='#')S++;
    if(!S)a[i]=1;
  }
  r(i,w){
    int S=0;
    r(j,h)if(s[j][i]=='#')S++;
    if(!S)b[i]=1;
  }
  r(i,h){
    if(a[i]==1)continue;
    r(j,w)if(b[j]==0)cout<<s[i][j];
    cout<<endl;
  }
}
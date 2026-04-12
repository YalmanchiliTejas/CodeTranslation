#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  int h,w;
  cin>>h>>w;
  char a[110][110];
  bool b[110]={},c[110]={},f=0;
  fr(i,h) fr(j,w) cin>>a[i][j];
  fr(i,h) fr(j,w) if(a[i][j]=='#') b[i]=1;
  fr(j,w) fr(i,h) if(a[i][j]=='#') c[j]=1;
  fr(i,h){
    if(!b[i]) continue;
    fr(j,w){
      if(c[j]) cout<<a[i][j];
    }
    cout<<endl;
  }
}
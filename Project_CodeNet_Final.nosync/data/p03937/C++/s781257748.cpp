#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
#define int long long
int n,l,r,a[100001],b[100001],f;
main(){
  cin>>l>>r;
  string s[l];
  r(i,l)cin>>s[i];
  for(int i=1;i<l;i++){
    for(int j=0;j<r-1;j++){
      if(s[i][j]=='#'&&s[i-1][j+1]=='#')f++;
    }
  }
  if(f)cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
}
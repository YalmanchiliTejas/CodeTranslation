#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  int n,m;
  cin>>n>>m;
  bool check[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) check[i][j]=false;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    check[a-1][b-1]=true;
    check[b-1][a-1]=true;
  }
  int a[n-1];
  for(int i=0;i<n-1;i++) a[i]=i+1;
  int ans=0;
  do{
    bool temp=true;
    for(int i=0;i<n-1;i++){
      if(i==0 && !check[0][a[0]]) temp=false;
      if(i>=1 && !check[a[i-1]][a[i]]) temp=false; 
    }
    if(temp) ans++;
  }while(next_permutation(a,a+n-1));
  cout<<ans<<endl;
  return 0;
}
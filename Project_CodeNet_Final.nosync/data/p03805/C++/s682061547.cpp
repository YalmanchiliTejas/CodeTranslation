#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a,b,cnt=0;
  int mp[10][10]={};
  cin>>n>>m;
  int p[n];

  for(int i=0;i<n;++i){
    p[i]=i+1;
  }

  for(int i=0;i<m;++i){
    cin>>a>>b;
    mp[a][b]=mp[b][a]=1;
  }

  do{
    if(p[0]!=1)break;
    bool ans=true;

    for(int i=1;i<n;++i){
      if(mp[p[i]][p[i-1]]!=1){
	ans=false;
      }
    }

    if(ans)cnt++;

  }while(next_permutation(p,p+n));

  cout << cnt << endl;

  return 0;
}

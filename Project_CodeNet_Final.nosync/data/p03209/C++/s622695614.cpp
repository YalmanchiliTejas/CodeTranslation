#include <bits/stdc++.h>
using namespace std;
//解答写し
long long nagasa[51],niku[51];
long long keisan(long long k,long long x){
  if(x==nagasa[k])return niku[k];
  long long kotae=0;
  x--;
  if(x>0){
    long long l=min(x,nagasa[k-1]);
    kotae+=keisan(k-1,l);
    x-=l;
  }
  if(x>0){
    kotae++;
    x--;
  }
  if(x>0){
    long long l=min(x,nagasa[k-1]);
    kotae+=keisan(k-1,l);
    x-=l;
  }
  return kotae;
}
int main() {
  int n;
  cin>>n;
  long long m;
  cin>>m;
  nagasa[0]=1;
  niku[0]=1;
  for(int i=1;i<=n;i++){
    nagasa[i]=nagasa[i-1]*2+3;
    niku[i]=niku[i-1]*2+1;
  }
  cout<<keisan(n,m)<<endl;
}

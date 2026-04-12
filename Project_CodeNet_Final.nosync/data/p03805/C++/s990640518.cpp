#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,i,j;
  int ans=0;
  cin>>N>>M;
  vector<int>a(M),b(M),c(M),r(N);
  for(i=0;i<M;i++){
    cin>>a[i]>>b[i];
    c[i]=a[i]*b[i]*100+a[i]+b[i];
  }
  for(i=0;i<N;i++)r[i]=i+1;
  for(i=0;i<N-1;i++){
    for(j=0;j<M;j++){
      if(r[i]*r[i+1]*100+r[i]+r[i+1]==c[j])break;
    }
    if(j==M)break;
}
if(i==N-1)ans++;
  while(next_permutation(r.begin(),r.end())){
    if(r[0]!=1)continue;
    for(i=0;i<N-1;i++){
      for(j=0;j<M;j++){
        if(r[i]*r[i+1]*100+r[i]+r[i+1]==c[j])break;
      }
      if(j==M)break;
  }
  if(i==N-1)ans++;
}
cout<<ans<<endl;
}

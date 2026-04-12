#include <bits/stdc++.h>
using namespace std;

int kaijo(int N){
  int ans=1;
  for(int i=1;i<=N;i++){
    ans*=i;
  }
  return ans;
}


int main() {
long N,M;
cin>>N>>M;
vector<vector<long>> l(N, vector<long>(N));

for(int i=0;i<M;i++){
  int a,b;
  cin>>a>>b;
  a--;
  b--;
  l[a][b]=1;
  l[b][a]=1;
}
vector<int> d(N);
  for(int i=0;i<N;i++) d[i]=i+1;
int ans=0;
  for(int i=0;i<kaijo(N-1);i++){
    bool flg=true;
    int j=0;

    while(j<N-1){
      if(l[d[j+1]-1][d[j]-1]==0) {
        flg=false;
        break;
      }
      j++;
    }

    if(flg) ans++;
    next_permutation(d.begin(),d.end());
  }
cout<<ans<<endl;
}

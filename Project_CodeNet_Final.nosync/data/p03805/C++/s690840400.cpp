#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  const int n=N;
  vector<int> v(n);
  for(int i=1;i<=N;i++){
    v.at(i-1)=i;
  }
  int d[9][9]={0};
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    d[a][b]=1;
    d[b][a]=1;
  }
  int ans=0;
  do{
    bool check=true;
    for(int i=0;i<N-1;i++){
      if(d[v.at(i)][v.at(i+1)]==0) check=false;
    }
    if(check) ans++;
  }  while(next_permutation(v.begin(), v.end()) && v.at(0)==1);
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int ans=0;
  std::vector<int> yakusu;
  for(int i=0;i<N;i++)
    if(v[i]>1)yakusu.push_back(v[i]);
  for(int i=0;i<N;i++)
    for(int j=2;j*j<=v[i];j++)
      if(v[i]%j==0){
        yakusu.push_back(j);
        yakusu.push_back(v[i]/j);
      }
  for(int p:yakusu){
    int res=0;
    for(int i=0;i<N;i++)
      if(v[i]%p==0)res+=v[i];
    ans=max(ans,res);
  }
  fin(ans);
}


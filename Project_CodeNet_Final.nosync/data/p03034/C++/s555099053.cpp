#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template

//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N),used(N,-1);
  for(int i=0;i<N;i++)cin>>v[i];
  int fans=0;
  for(int k=1;k<=N;k++){
    int ans=0;
    for(int j=k;j<N-1-k;j+=k){
      ans+=v[j];ans+=v[N-1-j];
      if(used[j]==k)break;used[j]=k;
      if(used[N-1-j]==k)break;used[N-1-j]=k;
      fans=max(ans,fans);
    }
  }
  cout<<fans<<endl;
}

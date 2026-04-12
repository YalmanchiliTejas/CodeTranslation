#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll N,X;

ll p_sums[51];
ll all_sums[51];

ll dfs(ll t, ll layer){
  if(layer==0)return 1;
  if (t<=0)return 0;
  ll mid = all_sums[layer]/2;
  if(mid==t){
    return p_sums[layer-1] + 1;
  } else if (t < mid) {
    return dfs(t-1, layer-1);
  } else {
    return p_sums[layer-1] + 1 + dfs(t-mid-1, layer-1);
  }
}

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  cin>>N>>X;
  p_sums[0]=1;
  all_sums[0]=1;
  for(int i=1;i<=N;i++){
    p_sums[i] = p_sums[i-1]*2 + 1;
    all_sums[i] = all_sums[i-1]*2 + 3;
  }
  ll ans=dfs(X-1, N);
  cout<<ans<<endl;
  
  return 0;
}

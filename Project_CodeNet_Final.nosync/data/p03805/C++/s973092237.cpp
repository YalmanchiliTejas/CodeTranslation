#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>>g(n,vector<int>(0));
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans=0;
  vector<int>array(0);
  rep(i,n) array.push_back(i);
  do{
    rep(i,n-1){
      if(vector_finder(g[array[i]],array[i+1])!=1)break;
      if(i==n-2) ans++;
    }
  }while(next_permutation(array.begin()+1,array.end()));
  cout<<ans<<endl;
}

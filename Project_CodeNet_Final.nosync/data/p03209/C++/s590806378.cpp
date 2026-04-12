#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
vector<ll> len(51,1);

ll dfs(int i,ll j){
  if(i==0) return 1;
  if(j<=1) return 0;
  if(j<=len.at(i-1)+1) return dfs(i-1,j-1);
  if(j<=len.at(i-1)+2) return dfs(i-1,len.at(i-1))+1;
  if(j<=len.at(i)-1) return dfs(i-1,len.at(i-1))+dfs(i-1,j-len.at(i-1)-2)+1;
  return 2*dfs(i-1,len.at(i-1))+1;
}
 
int main() {
  int n;
  ll x;
  cin >> n >> x;
  rep(i,50) len.at(i+1) = 2*len.at(i) + (3);
  cout << dfs(n,x) << endl;  
  return 0;
}






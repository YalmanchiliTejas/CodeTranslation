#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Graph = vector<vector<LL>>;

long long gcd(long long a, long long b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
long long chmax(long long a,long long b){
  a = max(a,b);
}
long long chmin(long long a, long long b){
  a = min(a,b);
}
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}



int main() {
  LL n,k,sum=0,a=0,b=0,c=0,d=0,ans=0;
  LL MOD = 1000000007;
  LL INF = 1LL << 60;
  string S="";
  cin >> a >> b;
  if(a==b) S = "Yes";
  else S = "No";
  cout << S << endl;
}
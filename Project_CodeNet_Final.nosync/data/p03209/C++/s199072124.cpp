#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;
const lli e3 = 1 << 13;
const lli INF = 1ll << 62;

lli n,x;
lli p[e5];
lli b[e5];

lli dfs(lli l,lli x){
  if(x == 0) return 0;
  if(p[l]+b[l] == x) return p[l];
  if(p[l-1]+b[l-1]+2 < x) return dfs(l-1,x-(p[l-1]+b[l-1])-2) + p[l-1] + 1;
  if(p[l-1]+b[l-1]+2 == x) return p[l-1] + 1;
  if(p[l-1]+b[l-1]+1 == x) return p[l-1];
  return dfs(l-1,x-1);
}

int main(){
  cin >> n >> x;
  p[0] = 1;
  b[0] = 0;
  for(lli i = 0;i < n;i++){
    p[i+1] = 0 + p[i] + 1 + p[i] + 0;
    b[i+1] = 1 + b[i] + 0 + b[i] + 1;
  }
  cout << dfs(n,x) << endl;
}

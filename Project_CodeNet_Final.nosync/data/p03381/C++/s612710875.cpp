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

lli n;
vll x,idx,ans;

int main(){
  cin >> n;
  x = vll(n);
  for(lli i = 0;i < n;i++) cin >> x[i];
  idx = vll(n);
  ans = vll(n);
  iota(idx.begin(),idx.end(),0ll);
  sort(idx.begin(),idx.end(),[](lli a,lli b){
    return x[a] < x[b];
  });
  sort(x.begin(),x.end());
  for(lli i = 0;i < n/2;i++){
    ans[idx[i]] = x[n/2];
  }
  for(lli i = n/2;i < n;i++){
    ans[idx[i]] = x[n/2-1];
  }
  for(lli i = 0;i < n;i++){
    cout << ans[i] << endl;
  }
  return 0;
}


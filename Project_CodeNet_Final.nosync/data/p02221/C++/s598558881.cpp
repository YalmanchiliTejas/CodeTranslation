#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

void solve(vecint&& p, string& s, vecint& res, int offset, int base) {
  vecint even;
  vecint odd;
  int n = p.size();
  if (n == 1) {
    res[offset] = p.front();
    return;
  }
  REP(i,n/2) {
    int p0 = p[2*i];
    int p1 = p[2*i+1];
    int p2 = p[(2*i+2)%n];
    int ep0 = min(p0, p1);
    int ep1 = max(p0, p1);
    if (s[ep1-ep0-1] == '1') even.push_back(ep1);
    else even.push_back(ep0);
    int op0 = min(p1, p2);
    int op1 = max(p1, p2);
    if (s[op1-op0-1] == '1') odd.push_back(op1);
    else odd.push_back(op0);
  }
  solve(std::move(even), s, res, offset, base*2);
  solve(std::move(odd), s, res, offset+base, base*2);
}

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  int p2 = 1<<n;
  vecint p(p2);
  for(auto&& e:p) cin>>e;
  vecint result(p2);
  solve(std::move(p),s,result,0,1);
  for(auto&& e:result){
    cout<<e<<'\n';
  }
  cout<<flush;
  return 0;
}


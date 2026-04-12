#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) {return a = min(a, b);}
template <typename T> T &chmax(T &a, const T &b) {return a = max(a, b);}

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
  char tmp = S[0];
  REP(i, 3){
    if(tmp != S[i]) { cout << "Yes" << endl; return; }
  }
  cout << "No" << endl;
  return;
}

int main(){
    std::string S;
  std::cin >> S;
    solve(S);
    return 0;
}

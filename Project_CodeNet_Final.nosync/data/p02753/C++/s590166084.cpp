#include <bits/stdc++.h>

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define ALL(x) (x).begin(),(x).end()
#define INF 999999999
using namespace std;
#define lint long long

int main()
{
  int N = 3;
  int out =0;
  //cin >> N;
  string S;
  cin >> S;
  vector<int> a(N);
  FOR(i,1,N){
    if(S[i-1] != S[i]){
      out = 1;
    }
  }
  if(out) cout << "Yes";
  else cout << "No";
  return 0;
}
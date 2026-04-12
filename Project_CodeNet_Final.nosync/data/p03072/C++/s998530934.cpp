#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)      for(int i = 0; i < (n); ++i)
#define all(c)         begin(c), end(c)
#define rall(c)        rbegin(c), rend(c)
#define SZ(a)          ((ll) a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  int ma=0;
  int ans=0;
  rep(i,N){
    if(H[i]>=ma){
      ans++;
      ma=H[i];
    }
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i )
#define rep_rev(n,i) for(ll i = n; i >= 0; --i )
using namespace std;
const long long INF = 1LL << 60;

int N,M;

int main(){
  cin >> N >> M;
  if(N == M) cout << "Yes";
  else cout << "No";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

ll N,X;
vector<ll> A,B;

ll dfs (int N,ll x) {
  if (N == 0) return 1;
  if (x == 1) return 0;
  if (x == 2 + A[N-1]) return 1 + B[N-1];
  if (x == A[N]) return B[N];
  if (x > 2 + A[N-1]) return dfs(N-1,x - 2 - A[N-1]) + 1 + B[N-1]; 
  if (x < 2 + A[N-1]) return dfs(N-1,x-1);
}

int main() {
  cin >> N >> X;

  A.resize(N+1); B.resize(N+1);
  A[0] = 1;
  B[0] = 1;
  int k;
  rep(i,N) {
    A[i+1] = 2 * A[i] + 3;
    B[i+1] = 2 * B[i] + 1;
  }

  cout << dfs(N,X) << endl;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> b_vec(51, 1);
vector<ll> p_vec(51, 1);

ll dfs(int n, ll x){
  if (n == 0)
    if (x <= 0) return 0;
    else return 1;
  else if (x <= 1 + b_vec.at(n-1)) return dfs(n-1, x-1);
  else return p_vec.at(n-1) + 1 + dfs(n-1, x-2-b_vec.at(n-1));
}
 
int main() {
  int N;
  ll X;
  cin >> N >> X;
  for (int i = 1; i < N+1; i++) {
    b_vec.at(i) = b_vec.at(i-1) * 2 + 3;
    p_vec.at(i) = p_vec.at(i-1) * 2 + 1;
  }

  cout << dfs(N, X) << endl;
}
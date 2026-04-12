
#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;
using lld = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll N;
  cin >> N;
  vector<ll> A(N);

  loop(0, N, i) {
    cin >> A[i];
  }

  ll MOD = 1e9+7;
  vector<ll> B(N);
  B[N-1] = A[N-1];
  for(ll i=N-2; i>=0; --i) {
    B[i] = (A[i] + B[i+1]) % MOD;
  }

  ll sum = 0;
  loop(0, N-1, i) {
    ll m = A[i] * B[i+1];
    sum += m;
    sum %= MOD;
  }
  print(sum);

}
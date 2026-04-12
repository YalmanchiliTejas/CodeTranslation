#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll C = 1000000007;
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll result = 0;
  //   for (ll i = 0; i < N - 1; i++) {
  //     ll sum = 0;

  //     for (ll j = i + 1; j < N; j++) {
  //       sum += A[j];
  //     }
  //     result += A[i] * sum;
  //     result = result % C;
  //   }
  ll sum = 0;
  for (ll i = 0; i < N - 1; i++) {
    sum += A[N - 1 - i];
    sum = sum % C;
    result += sum * A[N - 2 - i];
    result = result % C;
  }

  cout << result << endl;

  return 0;
}
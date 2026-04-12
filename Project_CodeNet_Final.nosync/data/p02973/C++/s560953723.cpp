#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(ll a, ll b) {
  return a>=b;
}

int main()
{
  ll N;
  scanf("%lld",&N);
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    scanf("%lld",&A[i]);
  }

  deque<ll> d;
  for (int i=0; i<N; i++) {
    int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
    if (p == 0) d.push_front(A[i]);
    else d[p-1] = A[i];
  }
  cout << d.size() << endl;

  return 0;
}


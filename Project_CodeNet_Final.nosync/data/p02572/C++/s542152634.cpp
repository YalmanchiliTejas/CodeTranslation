#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ll n;
  ll k = 1000000000 + 7;
  cin >> n;
  ll b = 0;
  vector<ll> vec(n+1);
  for (int i = 1; i <= n; i++)
  {
    cin >> vec[i];
  }
  vector<ll> A(n, 0);
  for (int i = 2; i <= n; i++)
  {
    A[1] += vec[i];
  }
  for (int i = 2; i < n; i++)
  {
    A[i] = A[i - 1] - vec[i];
  }
  for (int i = 1; i < n;i++){
    A[i] = A[i] % k;
  }
  for (int i = 1; i < n;i++){
    b += vec[i] * A[i];
    if(b>=k){
      b = b % k;
    }
  }
  cout << b << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)cin >> A[i];
    vector<ll> tmp(N-1);
    ll cnt = 0;
    ll total = 0;
    for (int i = N - 1; i > 0; i--) {
      cnt += A[i];
      //cout << "cnt"<<cnt<< endl;
      tmp[i - 1] = cnt % 1000000007;
    }
    for (int i = 0; i < N -1; i++) {
      //cout << "ai "<<A[i] << endl;
      //cout << "tmp " << tmp[i] << endl;
      total += ((A[i]%1000000007) *tmp[i])%1000000007;
      //cout << "total " << total << endl;
    }
    cout << total%1000000007<< endl;
    return 0;
}
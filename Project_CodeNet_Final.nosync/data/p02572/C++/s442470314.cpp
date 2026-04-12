#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const ULL MOD = 1000000007;
#define rep(i, ns, ne) for (ULL i = ns; i < ne; ++i)

/*
int main() {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<long long> B(N + 1, 0); //累積和テーブル
        int mod = 1000000007;

        for (int i = 0; i < N; i++)
        {
                cin >> A[i];
                B[i + 1] = B[i] + A[i];
        }

        long ans = 0;

        //i について全探索する
        for (int i = 0; i < N; i++)
        {
                //累積和を使ってA[i+1] + ... + A[N] を求める
                long long sum = (B[N] - B[i + 1]) % mod;

                ans += A[i] * sum;
                ans %= mod;
        }

        cout << ans << endl;
}*/

int main() {
  ULL N;
  cin >> N;
  vector<ULL> a(N);
  vector<ULL> b(N + 1,0);
  rep(i, 0, N) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  ULL sum, ans = 0;
  rep(i, 0, N) {
    sum = (b[N] - b[i + 1]) % MOD;
    ans = (ans + a[i] * sum) % MOD;
  }

  cout << ans << endl;
  getchar();
}
#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INF = 1LL << 60;

 ll rec(int n, long long x) {
     if (n == 0) return 1;
     ll len = (1LL << (n + 1)) - 3; // n - 1のバーガー長
     ll num = (1LL << n) - 1; // n - 1のパティ数
     if (x == 1) return 0;
     else if (x <= len + 1) return rec(n - 1, x - 1);
     else if (x == len + 2) return num + 1;
     else if (x <= (len + 1) * 2) return num + 1 + rec(n - 1, x - len - 2);
     else return num * 2 + 1;
 }

 int main() {
     int N; ll X;
     cin >> N >> X;
     cout << rec(N, X) << endl;
 }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; typedef long double ld;
const int INF32 = 1e9+10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N; cin >> N;
  ll A[100010]; ll B[100010];
  for (int i = 0; i < N; i++) {
    cin >> A[i]; B[i] = A[i];
  }
  sort(A, A+N);
  int l = 0; int r = 0;
  ll cl = A[0]; ll cr = A[0];
  ll ans1 = 0;
  for (int i = 0; i < (N-1)/2; i++) {
    if (i % 2 == 0) {
      if (abs(A[N-1-i] - cr) + abs(A[N-2-i] - cl) > abs(A[N-1-i] - cl) + abs(A[N-2-i] - cr)) {
        ans1 += abs(A[N-1-i] - cr) + abs(A[N-2-i] - cl);
        r = N-1-i; l = N-2-i;
        cr = A[r]; cl = A[l];
      } else {
        ans1 += abs(A[N-1-i] - cl) + abs(A[N-2-i] - cr);
        r = N-2-i; l = N-1-i;
        cr = A[r]; cl = A[l];
      }
    } else {
      if (abs(A[i] - cr) + abs(A[i+1] - cl) > abs(A[i] - cl) + abs(A[i+1] - cr)) {
        ans1 += abs(A[i] - cr) + abs(A[i+1] - cl);
        r = i; l = i+1;
        cr = A[r]; cl = A[l];
      } else {
        ans1 += abs(A[i] - cl) + abs(A[i+1] - cr);
        r = i+1; l = i;
        cr = A[r]; cl = A[l];
      }
    }
  }
  if (N % 2 == 0) {
    ans1 += max(abs(A[(((N-1)/2)/2)*2+1] - cr), abs(A[(((N-1)/2)/2)*2+1] - cl));
  }
  sort(B, B+N, greater<int>());
  l = 0; r = 0;
  cl = B[0]; cr = B[0];
  ll ans2 = 0;
  for (int i = 0; i < (N-1)/2; i++) {
    if (i % 2 == 0) {
      if (abs(B[N-1-i] - cr) + abs(B[N-2-i] - cl) > abs(B[N-1-i] - cl) + abs(B[N-2-i] - cr)) {
        ans2 += abs(B[N-1-i] - cr) + abs(B[N-2-i] - cl);
        r = N-1-i; l = N-2-i;
        cr = B[r]; cl = B[l];
      } else {
        ans2 += abs(B[N-1-i] - cl) + abs(B[N-2-i] - cr);
        r = N-2-i; l = N-1-i;
        cr = B[r]; cl = B[l];
      }
    } else {
      if (abs(B[i] - cr) + abs(B[i+1] - cl) > abs(B[i] - cl) + abs(B[i+1] - cr)) {
        ans2 += abs(B[i] - cr) + abs(B[i+1] - cl);
        r = i; l = i+1;
        cr = B[r]; cl = B[l];
      } else {
        ans2 += abs(B[i] - cl) + abs(B[i+1] - cr);
        r = i+1; l = i;
        cr = B[r]; cl = B[l];
      }
    }
  }
  if (N % 2 == 0) {
    ans2 += max(abs(B[(((N-1)/2)/2)*2+1] - cr), abs(B[(((N-1)/2)/2)*2+1] - cl));
  }

  cout << max(ans1, ans2) << endl;
}

 #include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 5;

int n;
long long a[N];
long long b[N];

int solve() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 1; j < n; ++j) {
      if (a[j] > a[k]) {
        k = j;
      }
    }
    if (a[k] < n) {
      break;
    }
    ++cnt;
    a[k] -= n + 1;
    for (int i = 0; i < n; ++i) {
      a[i]++;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n; 
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memcpy(b, a, sizeof(a));
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  long long ans = LLONG_MAX;
  for (int i = 0; i < n + 1; ++i) {
    long long det = 0;
    for (int j = 0; j < n; ++j) {
      det += (b[j] + i) % (n + 1);
    }
    long long t = sum - det;
    if (t % (n + 1) == i) {
      memcpy(a, b, sizeof(a));
      for (int k = 0; k < n; ++k) {
        a[k] = (a[k] + t) % (n + 1);
      }      
      ans = min(ans, solve() + t);
    }
  }
  cout << ans << endl;
  return 0;
}

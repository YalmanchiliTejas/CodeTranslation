#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod 1e9+7

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  int b, c;
  int a[5];
  while(cin >> b >> c) {
    if(!b && !c) return 0;
    a[0] = b + c;
    int m = a[0];
    rep(i, 0, 4) cin >> b >> c, a[i + 1] = b + c, m = max(m, a[i + 1]);
    rep(i, 0, 5) if(a[i] == m) cout << (char)('A' + i) << " " << m << endl;
  }
}
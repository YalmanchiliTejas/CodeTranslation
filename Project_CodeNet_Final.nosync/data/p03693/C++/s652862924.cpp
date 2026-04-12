#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  string a, b, c;
  int d;
  cin >> a >> b >> c;
  istringstream iss(a + b + c);
  iss >> d;
  cout << (d % 4 == 0 ? "YES" : "NO") << endl;
}

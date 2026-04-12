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
  int a[101] = {};
  rep(i, 0, 12) {
    int b;
    cin >> b;
    a[b]++;
  }
  int f = 0;
  rep(i, 0, 100) if(a[i] % 2 == 1) f = 1;
  cout << (f ? "no" : "yes") << endl;
}
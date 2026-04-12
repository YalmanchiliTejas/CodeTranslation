#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)1e9+7

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
  char c;
  cin >> c;
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
  else cout << "consonant" << endl;
}

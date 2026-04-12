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
  string s;
  cin >> s;

  rep(i, 0, s.length() - 1) {
    if(s[i] == 'A' && s[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}

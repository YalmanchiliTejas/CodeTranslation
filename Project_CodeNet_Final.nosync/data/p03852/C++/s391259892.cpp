//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    char c; cin >> c;
    string vowel = "aiueo";
    rep(i, 0, vowel.size()) {
      if (c == vowel[i]) {
        cout << "vowel" << endl;
        return 0;
      }
    }
    cout << "consonant" << endl;
}

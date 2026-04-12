#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    char c; cin >> c;
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    bool ok = false;
    rep(i, 5) {
        if(v[i] == c) ok = true;
    }
    if(ok) cout << "vowel";
    else cout << "consonant";
}

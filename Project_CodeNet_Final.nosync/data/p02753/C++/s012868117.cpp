#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    bool a = false;
    bool b = false;
    rep(i, 3){
        if(S[i] == 'A') a = true;
        if(S[i] == 'B') b = true;
    }
    if(a && b) cout << "Yes";
    else cout << "No";
}

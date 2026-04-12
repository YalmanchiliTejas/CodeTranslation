#include<iostream>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    char s[3];
    rep(i, 3) cin >> s[i];

    bool exist = false;

    if (s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) exist = true;

    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    char c;
    cin >> c;
    bool ans = false;

    if (c == 'a') ans = true;
    if (c == 'e') ans = true;
    if (c == 'i') ans = true;
    if (c == 'o') ans = true;
    if (c == 'u') ans = true;
    

    if(ans) {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }

    return 0;
}
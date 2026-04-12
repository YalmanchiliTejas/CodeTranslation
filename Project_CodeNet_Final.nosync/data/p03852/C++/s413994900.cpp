#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

int main() {

    char c; cin >> c;
    char m[] = { 'a', 'e', 'i', 'o', 'u' };

    rep(i, 5) {
        if (c == m[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    char in;
    cin >> in;
    for (auto &vo : vowel) {
        if (in == vo) {
            cout << "vowel\n";
            return 0;
        }
    }
    cout << "consonant\n";
}

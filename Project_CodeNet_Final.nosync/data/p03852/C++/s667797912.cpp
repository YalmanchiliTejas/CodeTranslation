#include <bits/stdc++.h>
using namespace std;

#define MOD (1000 * 1000 * 1000 + 7)
#define INF (1LL << 60)
#define pb push_back
#define po pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;

int main() {

    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

    char c;
    cin >> c;

    for (auto &v : vowels) {
        if (v == c) {
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;

    return 0;
}
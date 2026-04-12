#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1001001001
#define LINF (1LL << 62)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solv() {
    vector<char> aiueo = {'a', 'i', 'u', 'e', 'o'};
    char c;
    cin >> c;
    rep(i, aiueo.size()) {
        if (c == aiueo[i]) {
            cout << "vowel" << endl;
            return;
        }
    }
    cout << "consonant" << endl;
}

int main() {
    solv();
    return 0;
}
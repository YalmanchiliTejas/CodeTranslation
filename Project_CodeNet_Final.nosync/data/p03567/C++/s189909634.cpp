#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A') {
            if (s[i + 1] == 'C') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

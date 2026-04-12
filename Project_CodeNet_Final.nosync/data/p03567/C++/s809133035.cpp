#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S, answer = "";
    bool flag = false;
    cin >> S;
    for (int i = 0; i < S.size(); ++i) {
        if (i - 1 >= 0 && S[i - 1] == 'A' && S[i] == 'C') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i+1 < n; ++i) {
        if(s.substr(i, 2) == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

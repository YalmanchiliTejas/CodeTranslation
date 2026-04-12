#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    string t;
    cin >> t;

    string ac = "AC";
    for (int i = 0; i < t.size() - 1; i++) {
        if (t.substr(i, 2) == ac) {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
}
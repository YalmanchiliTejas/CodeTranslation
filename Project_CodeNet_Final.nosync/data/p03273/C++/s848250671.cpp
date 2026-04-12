#include "bits/stdc++.h"
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    vector<string> x(a);
    vector<bool>  l(a, false), r(a, false);

    for (int i = 0; i < a; i++) cin >> x[i];
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < b; k++) {
            if (x[i][k] == '#') {
                l[i] = true, r[k] = true;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        if (l[i]) {
            for (int k = 0; k < b; k++){
                if (r[k]) {
                    cout << x[i][k];
                }
            }
            cout << endl;
        }
    }

}
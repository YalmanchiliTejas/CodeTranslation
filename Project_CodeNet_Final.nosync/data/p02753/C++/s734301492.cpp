#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
    cin >> S;
 
    int a = 0;
    for (int i = 0; i < 3; i++) {
        if (S[i] == 'A') {
            a++;
        }
    }
 
    cout << ((a == 1 || a == 2) ? "Yes" : "No") << endl;

    return 0;
}
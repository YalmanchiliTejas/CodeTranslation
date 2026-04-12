#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
 
    string S;
    cin >> S;

    if (S[0] == 'A') {
        if (S[1] == 'A') {
            if (S[2] == 'A') {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
                cout << "Yes" << endl;
        }
    } else {
        if (S[1] == 'B') {
            if (S[2] == 'B') {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
                cout << "Yes" << endl;
        }
    }
 
    return 0;
}

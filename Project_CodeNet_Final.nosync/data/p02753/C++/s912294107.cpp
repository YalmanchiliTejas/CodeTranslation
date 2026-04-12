#include <bits/stdc++.h>

using namespace std;

int main() {
    string C;  
    cin >> C;
    char A = C[0];
    bool c = false;

    for (int i = 1;i < 3;i++) {
        if (C[i] != A) {
            c = true;
        } else {
            A = C[i];
        }
    }

    if (c) {
        cout << "Yes" << endl;      
    } else {
        cout << "No" << endl;
    }
    
}

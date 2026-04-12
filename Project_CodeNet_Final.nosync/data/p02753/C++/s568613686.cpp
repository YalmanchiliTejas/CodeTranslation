#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
  
    char S[3];

    rep(i, 3) {
        cin >> S[i];
    }

    if (S[0] == S[1] && S[1] == S[2]) {
        cout << "No" << endl;

    }

    else {
        cout << "Yes" << endl;
    }
    return 0;

    
    }
    
    

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    string s;
    cin >> s;
    
    bool a, b;
    a = b = false;
    
    rep(i,3) {
        if(s[i] == 'A')
            a = true;
        if(s[i] == 'B')
            b = true;
    }
    
    if(a && b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}



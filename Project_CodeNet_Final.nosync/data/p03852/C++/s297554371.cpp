#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string c;
    bool ans;
    
    cin >> c;
    
    switch (c[0]) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            ans = true;
            break;
        default:
            ans = false;
            break;
    }
    
    cout << (ans ? "vowel" : "consonant") << endl;
    return 0;
}
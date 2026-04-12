#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
    
    char s;
    cin >> s;
    switch(s){
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            cout << "vowel" << endl;
            break;
        default:
            cout << "consonant" << endl;;
    }
    
    return 0;
}

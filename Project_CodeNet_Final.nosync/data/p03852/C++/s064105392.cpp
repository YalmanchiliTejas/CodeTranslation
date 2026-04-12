#include <bits/stdc++.h>
#define ll long long;

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char c; cin >> c;

    char m[10] = {"aiueo"};

    for (int i=0; i<5; i++)
    {
        if (c==m[i])
        {
            cout << "vowel" << "\n";
            return 0;
        }
    }

    cout << "consonant" << "\n";
    
    
    return 0;
}
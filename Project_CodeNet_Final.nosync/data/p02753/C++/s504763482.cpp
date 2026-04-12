#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    string s; cin >> s;
    int c = 0;
    for (auto x : s) {
        if (x == 'A') c++;
    }

    cout << (c != 0 and c <= 2 ? "Yes" : "No") << "\n"; 


    return 0; 
}


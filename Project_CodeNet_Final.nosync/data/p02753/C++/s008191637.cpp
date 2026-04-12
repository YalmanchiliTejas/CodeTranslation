#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    int a = 0;
    int b = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s.at(i) == 'A') a++;
        else b++;
    }

    if(a == 0 || b == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}
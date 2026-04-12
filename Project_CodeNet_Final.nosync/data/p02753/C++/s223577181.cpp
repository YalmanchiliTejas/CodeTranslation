#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << (s[0] == s[1] && s[1] == s[2] ? "No" : "Yes") << endl;
    
    return 0;
}
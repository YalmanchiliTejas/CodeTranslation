#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "No\n";
    else cout << "Yes\n";
}
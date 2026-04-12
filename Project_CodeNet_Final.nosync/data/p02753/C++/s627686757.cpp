#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    if(s[0] == s[1] and s[1] == s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
# include <stdio.h>
#include <bits/stdc++.h>

const int maxn = 3e5 + 111;

using namespace std;        

const int mod = 1e9 + 7;



string s;
int ans = 1e9;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    if(s[0] == '7' || s[0] == '3' || s[0] == '5') cout << "YES";
    else cout << "NO";
}
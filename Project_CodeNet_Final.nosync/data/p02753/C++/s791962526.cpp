#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using namespace std;

int main() {
    string s, ans="No";
    cin >> s;
    if (s[0]!=s[1] || s[1]!=s[2]) ans = "Yes";
    cout <<ans<< endl;
    return 0;
}
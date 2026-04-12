#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s, ans = "Yes";
    cin >> s;
    if(s == "AAA" || s == "BBB") ans = "No";
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e6 + 5;

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    bool flag = false;
    for (int i = 1; i < s.size(); ++ i){
        if (s[i] != s[i - 1]) flag = true;
    }
    if (flag) cout << "Yes";
    else cout << "No";
}
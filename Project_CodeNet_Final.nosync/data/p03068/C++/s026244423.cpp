#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
    int n; cin >> n;
   string s; cin >> s;
    int k; cin >> k;
    char ng = s[k - 1];
    for (int i = 0; i < n; ++i)
        cout << (s[i] == ng ? ng : '*');
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define mod (long long)1e9+7
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flg = true;
    for (int i = 1; i < 3; i++)
        flg &= s[i-1] == s[i];
    cout << (flg ? "No" : "Yes") << endl;
}

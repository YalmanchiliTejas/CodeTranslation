#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    rep(i, 2) {
        if (s[i] != s[i+1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}
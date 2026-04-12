#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    string s;
    int k;
    cin >> n;
    cin >> s;
    cin >> k;
    char c = s[k - 1];
    rep(i, n) {
        if(s[i] != c) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}
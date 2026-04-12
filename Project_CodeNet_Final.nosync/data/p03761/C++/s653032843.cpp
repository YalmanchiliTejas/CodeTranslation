#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

int a[50][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (char c : s)
            a[i][c - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        int mi = 1e9;
        for (int j = 0; j < n; ++j)
            mi = min(mi, a[j][i]);
        cout << string(mi, 'a'+i);
    }
}

#include <bits/stdc++.h>
using namespace std;

#define ios                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fr freopen("in.txt", "r", stdin)
#define ll long long
#define F first
#define S second
#define mem(v, x) memset(v, x, sizeof(v))
#define EB emplace_back
#define PB push_back
#define MP make_pair

int main()
{
    // fr;
    ios;

    string s;
    cin >> s;
    if (s[0] == s[1] && s[0] == s[2])
        cout << "No\n";
    else
        cout << "Yes\n";
}
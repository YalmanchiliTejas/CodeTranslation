#include <bits/stdc++.h>
#define mod 1e9+7
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
int dx[4] = {-1, 0, +1, 0}, dy[4] = {0, -1, 0, +1};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') a++;
        if (s[i] == 'B') b++;
    }
    if (a >= 1 && b >= 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

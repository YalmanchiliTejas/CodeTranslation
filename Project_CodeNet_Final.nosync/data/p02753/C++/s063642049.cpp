#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int cnt=0;
    string s;
    cin >> s;
    for (int i=0; i<3; i++)
        if (s[i]=='A') cnt++;
    if (!cnt || cnt==3) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

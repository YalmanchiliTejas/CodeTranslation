/////////////////////////////////////////////template 1
#include <bits/stdc++.h>
#define MOD 1000000007
//for(int i=0; i<n; ++i)
using namespace std;
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2])
        cout << "No";
    else
        cout << "Yes";
    cout << endl;

    return 0;
}
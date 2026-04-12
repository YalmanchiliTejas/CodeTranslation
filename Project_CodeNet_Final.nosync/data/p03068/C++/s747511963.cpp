#include <bits/stdc++.h>
//#pragma warning( disable : 4996 )
#define ll long long
#define pb push_back
#define endl '\n'
#define fastIO cin.tie( 0 );ios_base::sync_with_stdio( false )
#define pii pair<int, int>
#define eps 1e-13
#define N 14

using namespace std;

inline void init()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char tmp = s[k - 1];
    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] != tmp )
            s[i] = '*';
    }
    cout << s;
}

inline void solve()
{
    cout << endl;
}

int main()
{
    fastIO;
    init();
    solve();

    return 0;
}
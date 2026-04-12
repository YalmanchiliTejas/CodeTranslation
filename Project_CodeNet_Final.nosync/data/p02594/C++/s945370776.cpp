#include <bits/stdc++.h>

using namespace std;

#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define MOD 1000000007

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, i;

signed main()
{
    fast_IO;
    int test = 1;
    // cin >> test;
    while(test--)
    {
        cin >> n;
        if(n >= 30)
            return cout << "Yes", 0;
        cout << "No";
    }
    return 0;
} 
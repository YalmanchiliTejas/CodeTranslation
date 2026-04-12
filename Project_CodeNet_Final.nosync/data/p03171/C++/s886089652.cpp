#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define pb push_back
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vvi a(3001,vi(3001,0)),b(3001,vi(3001,0));
    for(int i = 0 ; i < n ; i++)
        cin >> a[0][i];
    
    for (int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < n - i ; j++)
        {
            ll t = a[0][j] + a[i - 1][j + 1] + b[i - 1][j + 1];
            a[i][j] = max(a[0][j] + b[i - 1][j + 1], a[0][j + i] + b[i - 1][j]);
            b[i][j] = t - a[i][j];
        }
    }
    cout << a[n-1][0] - b[n-1][0] << endl;
    return 0;
}
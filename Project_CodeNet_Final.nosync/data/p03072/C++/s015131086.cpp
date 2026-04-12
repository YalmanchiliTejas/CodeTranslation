#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double  
#define mp make_pair
inline void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
}
int main()
{
    io();
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        ans += (h >= mx);
        mx = max(mx, h);
    }
    cout << ans;
    return 0;
}
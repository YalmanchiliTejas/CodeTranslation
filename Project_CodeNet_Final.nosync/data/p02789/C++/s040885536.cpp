#include <bits/stdc++.h>
using namespace std;
#define ll long long
void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    if(m>=n){
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    
}

int main()
{
    //IO();
    int t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define deb(x) cerr << #x << ":" << x << "\n"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        ll i,j;
        cin>>i>>j;
        if(j>=i)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
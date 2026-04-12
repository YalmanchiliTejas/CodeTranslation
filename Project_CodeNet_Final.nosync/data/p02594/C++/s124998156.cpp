#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define rep(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
typedef pair< ll, ll > lpair;

void solve()
{
    ll x;
    cin >> x;
    if(x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
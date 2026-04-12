#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long int

void solve(ll caseNo)
{
    int n;
    cin >> n;
    if(n >= 30) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return;
}

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll cases;
    cases = 1;
    for(ll i=1;i<=cases;i++)
    {
        solve(i);
    }
    return 0;
}
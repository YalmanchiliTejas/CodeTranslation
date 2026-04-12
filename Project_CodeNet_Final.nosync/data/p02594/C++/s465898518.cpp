#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define eps 1e-9
#define pi acos(-1.0)
#define all(v) v.begin(),v.end()

#define MAX 500005

vector<ll> p;
bool vis[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll x;
    cin >> x;

    if(x<30) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
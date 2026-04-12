#include <bits/stdc++.h>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(ll i=a;i<=b;i++)

void solve()
{
    string s;
    cin >> s;

    if(s[0]==s[1] && s[1]==s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return;
}

int main() 
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    fastio

    ll t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
    
    return 0;
}
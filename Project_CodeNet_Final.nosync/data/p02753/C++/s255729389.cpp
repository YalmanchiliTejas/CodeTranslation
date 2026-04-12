/*
    ALWAYS REMMEMBER:
        NEVER GIVE UP !
        DON'T MESS WITH ME !!!
        "" THE EXPERT IN ANYTHING WAS ONCE A BEGINNER ""
*/

#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define f(i,a,b) for(ll i=a; i<=b; i++)
#define fi(i,a,b) for(ll i=a; i>=b; i--)
#define fa(x,b) for(auto x:b)
#define TC ll test_case; cin>>test_case; for(ll number=1 ; number <= test_case ; number ++ )
#define vll vector<ll>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (ll)(a).size()
#define sp(x) cout << fixed << setprecision(x);
#define ReadFile freopen("input.txt","r",stdin)
#define WriteFile freopen("output.txt","w",stdout)
#define endl "\n"

const ld pi = acos(-1);
const ll M=1e9+7,N=1e7+5,INF=1e18;

void solve()
{
    string s;
    cin >> s;

    if(s[0]=='A' && s[1]=='A' && s[2]=='A')
        cout << "No" << endl;
    else if(s[0]=='B' && s[1]=='B' && s[2]=='B')
        cout << "No" << endl;
    else 
        cout << "Yes" << endl;
}

int32_t main()
{
    FIO
    solve();
    return 0;
}
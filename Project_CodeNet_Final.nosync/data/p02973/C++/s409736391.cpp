#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define mp make_pair
#define bp __builtin_popcountll

const int N = 100005;
const int MOD = 1000000007;
const int MOD1 = 1000000009;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{
    ll n;
    cin >> n;
    multiset<ll> s;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        if(!s.size())    s.insert(x);
        else
        {
            ll mini = *s.begin();
            ll maxi = *s.rbegin();
            if(x<=mini)   s.insert(x);
            else if(x>maxi)
            {
                s.erase(s.find(maxi));
                s.insert(x);
            }
            else
            {
                auto it = s.lower_bound(x);
                it--;
                s.erase(it);
                s.insert(x);
            }
        }
    }
    cout<<s.size();
}

int main()
{
    FAST;
    ll t = 1;
  //  cin >> t;
    while(t--)
    {
        solve();
    }
}
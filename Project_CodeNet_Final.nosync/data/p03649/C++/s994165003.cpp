#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long int ll;
typedef vector< pair<int, int> > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const ll inf = 1e9;
const ll MOD = 1e9 + 7;
const ll nax = 1000000 + 10;

ll n, arr[nax];

bool is(ll mid)
{
    ll temp = mid;
    for(ll i = 1; i <= n; i++)
    {
        ll tosub = (arr[i] + 1 + mid - n);
        if(tosub <= 0)
            continue;
        if((tosub % (1 + n)) == 0)
            tosub = (tosub / (1 + n));
        else
            tosub =  (tosub / (1 + n)) + 1;
        temp -= tosub;
    }
    if(temp >= 0) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> arr[i];
    ll l = 0, r = 5e17;
    while(r - l > 1)
    {
        ll mid = (r + l) / 2;
        if(is(mid) == true)
            r = mid;
        else
            l = mid;
    }
    ll cnt = 0;
    ll ans = l;
    if(is(l + 1))
        ans = l + 1;

    for(ll i = (l - 1); i >= 0 && cnt++ <= 100000; i--)
    {
        if(is(i))
            ans = min(ans, i);
    }
    cout << ans;
    return 0;
}

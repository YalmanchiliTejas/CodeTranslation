#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define INF 1000000000000000000

ll n,m;
ll l[200010];
ll r[200010];
ll seg[900040];
ll lazy[900040];
bool push[900040];
vector<ll> lef[200010];
vector<pair<ll, ll> > rig[200010];
ll a[200010];
ll dp[200010];

ll combine(ll &a, ll &b) {
   return max(a, b);
}

void propagate(ll t, ll i, ll j) {
   if (push[t]) {
      seg[t] = seg[t] + lazy[t];
      if (i != j) {
         push[t*2] = true;
         push[t*2 + 1] = true;
         lazy[t*2] = lazy[t*2] + lazy[t];
         lazy[t*2 + 1] = lazy[t*2 + 1] + lazy[t];
      }
      push[t] = false;
      lazy[t] = 0;
   }
}

void update(ll t, ll i, ll j, ll l, ll r, ll x) {
   propagate(t, i, j);
   if (i > r || j < l) {
      return ;
   }
   if (l <= i && j <= r) {
      //base case : leaf node information to be stored here
      lazy[t] += x;
      push[t] = true;
      propagate(t, i, j);
      return ;
   }
   ll mid = (i + j) / 2;
   update(t*2, i, mid, l, r, x);
   update(t*2 + 1, mid + 1, j, l, r, x);
   seg[t] = combine(seg[2*t], seg[2*t+1]);
}
 
//Complexity: O(log n)
ll query(ll t, ll i, ll j, ll l, ll r) {
   propagate(t, i, j);
   if (i > r || j < l) {
      //base case: result of out-of-bound query
      return 0;
   }
   if (l <= i && j <= r) {
      return seg[t];
   }
   ll mid = (i + j) / 2;
   if (l <= mid) {
      if (r <= mid) {
         return query(t*2, i, mid, l, r);
      }
      else {
         ll a = query(t*2, i, mid, l, r);
         ll b = query(t*2 + 1,  mid + 1, j, l, r);
         return combine(a, b);
      }
   }
   else {
      return query(t*2 + 1,  mid + 1, j, l, r);
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    fr(i,1,m)
    {
        cin >> l[i] >> r[i] >> a[i];
        lef[l[i]].pb(a[i]);
        rig[r[i]].pb(mp(a[i],l[i]));
    }

    fr(i,1,n)
    {
        rep(j,lef[i].size())
        {
            update(1,0,n,0,i-1,lef[i][j]);
            // cout << lef[i][j] << " " << i << endl;
        }

        dp[i] = query(1,0,n,0,i-1);
        update(1,0,n,i,i,dp[i]);

        // cout << dp[i] << endl;
        rep(j,rig[i].size())
        {
            update(1,0,n,0,rig[i][j].ss-1,-rig[i][j].ff);
            // cout << rig[i][j].ss << " " << rig[i][j].ff << " " << dp[i] << " " << i << endl;

        }
    }

    ll ans = 0;

    fr(i,1,n)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

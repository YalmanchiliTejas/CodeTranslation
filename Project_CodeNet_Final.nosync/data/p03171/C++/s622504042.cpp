#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define ld long double
#define sz(a) (ll)(a).size()

typedef tree<pair<ll,ll> ,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

const int MAXN = 3005;

ll n, a[MAXN], dp[MAXN][MAXN][2];        // Value of X - Y for a(st to en) when player pl is to move

ll rec(ll st, ll en, ll pl)
{
	if(st > en) return 0;
	if(dp[st][en][pl] != -1) return dp[st][en][pl];
	if(pl == 0)
		return dp[st][en][pl] = max(a[st] + rec(st + 1, en, pl ^ 1), a[en] + rec(st, en - 1, pl ^ 1));
	else
		return dp[st][en][pl] = min(rec(st + 1, en, pl ^ 1) - a[st], rec(st, en - 1, pl ^ 1) - a[en]);
}

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << rec(0, n-1, 0) << endl;
    return 0;
}
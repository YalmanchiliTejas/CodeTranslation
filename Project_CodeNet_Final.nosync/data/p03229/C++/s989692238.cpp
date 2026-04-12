#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF 1e18//1234567890987654321
#define INF 1234567890
#define pb push_back
#define ins insert
#define f first
#define s second
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN 200006
#define MAXK 26
#define MAXX 15000006
#define ll long long int
#define rep0(kk, l1, l2)for(ll kk = l1; kk < l2; kk++)
#define rep1(kk, l1, l2)for(ll kk = l1; kk <= l2; kk++)
#define forit(it, A) for(set<ll>::iterator it = A.begin(); it != A.end(); it++)
#define cr(x) cerr << #x << " = " << x << "\n";
#define crA(x, A) cerr << #x << " = " << A[x] << "\n";
#define mmst(x, v) memset((x), v, sizeof ((x)));
#define bg(ms) (*ms.begin())
#define ed(ms) (*prev(ms.end(), 1))
#define addedge(a, b, c, v) v[(a)].pb(pi((b), (c))); v[(b)].pb(pi((a), (c)))
#define ph push
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
ll n,  fb, ans, cursum;
deque <ll> dq, A, temp;
void solve()
{
	fb = 0, ans = 0, dq.clear();
	// sort(all(A));
	dq.pb(A[0]);
	A.pop_front();
	while(A.empty() == 0)
	{
		if(fb==0)
		{
			if(!A.empty())dq.push_front(A.back());
			if(!A.empty())A.pop_back();
			if(!A.empty())dq.push_back(A.back());
			if(!A.empty())A.pop_back();
		}
		else
		{
			if(!A.empty())dq.push_front(A.front());
			if(!A.empty())A.pop_front();
			if(!A.empty())dq.push_back(A.front());
			if(!A.empty())A.pop_front();
		}
		fb = !fb;
	}
	if(db)for(auto i  : dq)cout << i << " ";
	for(ll i = 0; i < dq.size()-1; i++)
	{
		ans += llabs(dq[i] - dq[i+1]);
	}
}
int main()
{
	cin >> n;
	for(ll i = 0 ; i < n; i++)
	{
		ll t;
		cin >> t;
		A.pb(t);
		temp.pb(t);
	}
	sort(all(A));
	sort(all(temp), greater<ll>());
	solve();
	cursum = ans;
	A.clear();
	for(auto i : temp)A.pb(i);
	solve();
	ans = max(ans, cursum);
	cout << ans << "\n";
}

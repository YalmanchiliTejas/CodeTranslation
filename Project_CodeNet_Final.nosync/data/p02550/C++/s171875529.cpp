#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define len(x) int((x).size())
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define randint(n) uniform_int_distribution<int>(1, (n))(rng)

const ll p = 998244353LL;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	#ifdef ARTHUR_LOCAL
		ifstream cin("input.txt");
	#endif

	ll n,x,m;
	cin>>n>>x>>m;
	vector<bool> vis((int)m + 1);
	ll ans = 0LL;

	vector<ll> seq;

	while(!vis[(int)x])
	{
		vis[(int)x]=1;
		seq.push_back(x);
		n--;

		// cout << x << endl;

		ans += x;
		// ans %= m;

		if(n==0LL) 
		{
			cout << ans << endl;
			return 0;
		}

		x = x*x;
		x %= m;
	}

	reverse(all(seq));
	while(seq.back()!=x) seq.pop_back();
	reverse(all(seq));

	ll seq_sum = 0LL;

	for(auto thing : seq)
	{
		seq_sum += thing;
		// seq_sum %= m;
	}

	ans += ll(n/ll(len(seq))) * seq_sum;
	n -= ll(n/ll(len(seq))) * ll(len(seq));

	for(int i=0; i<(int)n; i++)
	{
		ans += seq[i];
		// ans %= m;
	}

	cout << ans << endl;
}
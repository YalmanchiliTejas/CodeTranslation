/*** akshaykumar99 ***/
 
#include<bits/stdc++.h> 
using namespace std;
 
const long long MOD = 998244353;
const long double PI = acos(-1);
const long long N = 2e5+1;
 
typedef long long ll;
typedef long double ld;

void test_case()
{
	ll n, x, m;
	cin >> n >> x >> m;
	if(x == 0 || m == 1)
	{
		cout << x << '\n';
		return;
	}
	ll ans = x, prev = x, curr = 0;
	vector<bool> done(m+1, 0);
	done[x] = 1;
	ll ind = 0;
	for(ll i = 2; i <= n; i++)
	{
		curr = prev * prev % m;
		if(done[curr])
		{
			ind = i;
			break;
		}
		done[curr] = 1;
		ans = curr + ans;
		prev = curr;
		if(curr == 0)
			break;
	}
	if(ind == 0 || curr == 0)
	{
		cout << ans << '\n';
		return;
	}
	ll left = n - ind + 1;
	ll z = curr;
	vector<ll> vv = {curr};
	ll sum = curr;
	while(1)
	{
		z = z * z % m;
		if(z == curr)
			break;
		sum += z;
		vv.push_back(z);
	}
	ll nn = vv.size();
	// cout << ind << ' ' << left << ' ' << nn << ' '; 
	ll tot = left / nn;
	// cout << sum * tot << ' ';
	ans = ans + sum * tot;
	left = left % nn;
	for(int i = 0; i < left; i++)
	{
		ans += vv[i];
	}
	cout << ans << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    ll tc=1;
    // cin>>tc;
    while(tc--)
        test_case();
    return 0;
}

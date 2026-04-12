#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define mem(x,n) memset(x,n,sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

ll mod = 1e9 + 7;

int main()
{
	faster;
	
	ll n;
	cin >> n;
	vector<ll> a(n),b(n);

	for(auto &x: a) cin >> x;
	
	b[n-1] = a[n-1];

	for(int i = n-2; i >= 0; i--){
		b[i] = (b[i+1] + a[i]) % mod;
	}

	ll sum = 0;

	sum = (b[1] * a[0]) % mod;

	for(int i = 1; i < n-1; i++){
		sum = (sum + ((a[i] * b[i+1]) % mod)) % mod;
	}
	cout << sum << endl;
	
	return 0;
}

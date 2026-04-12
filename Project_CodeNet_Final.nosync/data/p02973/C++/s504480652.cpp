#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll maxn = 200 * 1001;
const ll INF = 1e18;
const ll mod = 1e9+7;

vector<ll> g[maxn];
ll a[maxn], d[maxn];
ll n , m , k;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n; ll F = 1;
    for(ll i = 0; i < n; i++)
    {
	    cin>> a[i];
		if(i && a[i] != a[i-1])
			F = 0; 
	}
	if(F)
		return cout<< n, 0;
    reverse(a, a+n);

    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }

    cout<< ans;
}






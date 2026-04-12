#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll n, MOD=(ll)1e9+7;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++)
        cin >> v[i];
    vector<ll> suff(n);
    suff[n-1]=v[n-1];
    for(ll i=n-2; i>=0; i--)
        suff[i]=(v[i]+suff[i+1])%MOD;
    ll res=0;
    for(ll i=0; i<n-1; i++){
        ll tmp=(ll)v[i]*suff[i+1];
        tmp%=MOD;
        res=(res+tmp)%MOD;
    }
    cout << res << endl;
	return 0;
}

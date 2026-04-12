#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  fo(i,n) for(ll i=0;i<n;i++)
#define rfo(i,n) for(ll i=n;i>=0;i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define pb push_back
#define deb(x) cout<< #x << " = "<<x<<endl;
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
ll mod(ll a)
{
	return a%(1000000007);
}
void solve()
{
	ll n;
	cin>>n;
	vector<ll> A(n);
	fo(i,n)
	{
		cin>>A[i];
	}
	vector<ll> ss(n);
	ss[n-1] = A[n-1];
	for(ll i=n-2;i>=0;i--)
	{
		ss[i] =ss[i+1]+ A[i];
		ss[i] = mod(ss[i]);
	}
	ll ans =0;
	for(ll i = 1;i<n;i++)
	{
		ans = mod(ans)+ mod(A[i-1]*ss[i]);
		ans = mod(ans);
	}
	cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
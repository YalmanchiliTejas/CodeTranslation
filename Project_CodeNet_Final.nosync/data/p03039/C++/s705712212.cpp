#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (ll i = ll(a); i <= ll(b); i++)
 
ll m = 7 + 1e9;
ll p = 7 + 1e9;
 
ll fact[200001];
 
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
ll inv(ll a)
{
	ll x, y;
	ll g = gcd(a, m, x, y);
 
    x = (x % m + m) % m;
    return x;
}
 
void multiply(ll &a, vector<ll> B)
{
	for(auto b:B)
	{
		a*=b;
		a%=p;
	}
}
 
ll choose(ll a, ll b)
{
	ll ret=1;
	multiply(ret,{fact[a],inv(fact[b]),inv(fact[a-b])});
	return ret;
}
 
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
 
	//ifstream cin("input.txt");
	//ifstream cin("test.in");
	//ofstream cout("test.out");
 
	fact[0]=1;
 
	REP(i,1,200000)
	{
		fact[i]=i*fact[i-1];
		fact[i]%=p;
	}
 
	ll n,m,k;
	cin>>n>>m>>k;
 
	if(k==1)
	{
		cout << 0 << endl;
		return 0;
	}
 
	ll col11=1;
 
	multiply(col11,{n,n,m,m,n-1,inv(2)});
 
	ll col12=1;
 
	multiply(col12,{n,m,m,n-1,n+n-1,inv(6)});
 
	swap(n,m);
 
	ll col21=1;
 
	multiply(col21,{n,n,m,m,n-1,inv(2)});
 
	ll col22=1;
 
	multiply(col22,{n,m,m,n-1,n+n-1,inv(6)});
 
	ll ans = col11 - col12 + p;
	ans%=p;
	ans += col21 - col22 + p;
	ans%=p;
 
	multiply(ans,{choose(k,2),choose(n*m,k),inv(choose(n*m,2))});
 
	cout << ans << endl;
}
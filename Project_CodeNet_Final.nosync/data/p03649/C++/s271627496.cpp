
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll N = 200030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    998244353;
ll n;
ll arr[100];

int main()
{  fast
priority_queue<ll> pq;
cin>>n;
ll ans=0;
ll cnt=0;
for(ll i=0;i<n;i++)
{
	ll x;
	cin>>x;
	pq.push(x);
}
while(1)
{
	ll x=pq.top();
	pq.pop();
	if(x+cnt<n)
	break;
	ll y=((x+cnt)/n);
	ans+=y;
	pq.push(x-y*n-y);
	cnt+=y;
}
cout<<ans;
}



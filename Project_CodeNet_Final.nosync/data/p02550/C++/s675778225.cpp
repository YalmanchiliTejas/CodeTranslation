#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);(a)--)
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)

ll n, x, m;
ll flag[100005] = {0}, at[100005] = {0};

void reset()
{
	UU(i,0,1e5) flag[i] = -1;
	UU(i,0,1e5) at[i] = -1;
}

void input()
{
	cin>>n>>x>>m;
}

void solve()
{
	ll ans = 0, now = x % m, step = 0, i = 1;
	
	while(i <= n && flag[now] == -1)
	{
		ans += now;
		
		flag[now] = ans;
		at[now] = step;
		
		now *= now;
		now %= m;
		i++;
		step++;
	}
	
	ll life = n - i + 1;
	ll cost = ans - flag[now] + now;
	if(i != n)
	{
		ll need = step - at[now];
		ll mul = life / need;
		
		ans += cost * mul;
		life %= need;
	}
	
	while(life--)
	{
		ans += now;
		now *= now;
		now %= m;
	}
	
	cout<<ans<<endl;
}

void LetsRock()
{
	solve();
}
	
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
		reset();
		input();
		LetsRock();
	
	return 0;
}

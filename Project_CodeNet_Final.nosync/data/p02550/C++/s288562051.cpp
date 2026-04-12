#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}
ll dp[100002];

int main()
{
	for(int i = 0;i<100002;i++)dp[i]=-1;
	ll n,x,m;
	cin >> n >> x >> m;
	ll sum = 0;
	ll now = x;
	ll cnt = 1;
	map<ll,ll> mp;
	map<ll,ll> mp2;
	for(int i = 0;i<n;i++)
	{
		if(dp[now]!=-1)
		{
			ll roopsum = sum- mp[dp[now]]+mp2[dp[now]];
			ll rooptime = (n-cnt+1)/(cnt-dp[now]);
			sum += roopsum*rooptime;
			n-=cnt;
			n++;
			n %= cnt-dp[now];
			for(int j = 0;j<n;j++)
			{
				sum +=now;
				(now*=now)%=m;
			}
			cout<<sum<<endl;
			return 0;
		}
		sum+=now;
		mp2[cnt] = now;
		mp[cnt] = sum;
		dp[now] = cnt++;
		(now*=now)%=m;
	}
	cout<<sum<<endl;

}


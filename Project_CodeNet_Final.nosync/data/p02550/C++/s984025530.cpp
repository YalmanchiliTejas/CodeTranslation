#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_XM = 100005;
ll myuse[MAX_XM];

int main()
{
	ll N;
	cin >> N;
	ll X,M;
	cin >> X >> M;
	ll temp = X;
	myuse[temp] = ll(1);
	ll cnt = 1, loop = 0, startcnt = 0;
	while(true)
	{
		cnt++;
		temp = temp*temp%M;
		if (myuse[temp] > 0)
		{
			loop = cnt - myuse[temp];
			startcnt = myuse[temp];
			break;
		}
		else
		{
			myuse[temp] = cnt;
			//loopsum += temp;
		}
	}
	ll loopsum = temp, startnum = temp;
	temp = temp * temp % M;
	while(temp != startnum)
	{
		loopsum += temp;
		temp = temp * temp % M;
	}
	//cout << cnt << " " << loop << " " << loopsum << " " << startcnt << endl; 
	ll ans = (N - (startcnt - 1)) / loop * loopsum;
	ll res = (N - (startcnt - 1)) % loop;
	temp = X;
	rep(i,startcnt-1)
	{
		ans += temp;
		temp = temp * temp % M;
	}
	temp = startnum;
	rep(i,res)
	{
		ans += temp;
		temp = temp * temp % M;
	}
	cout << ans << endl;
	return 0;
}
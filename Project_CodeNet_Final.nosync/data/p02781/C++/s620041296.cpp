#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][2][200][1000], k;
vector <ll> num;

ll solve(ll isStart, ll isSmall, ll pos, ll val)
{
    if(pos == 0)
    {
		if(val==k) return 1;
		return 0;
	}
	
    ll &ret = dp[isStart][isSmall][pos][val];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i != 0) + val);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, val+1);

        rt += solve(1, 1, pos - 1, 0);
    }

    return ret = rt;
}

ll calc(string n)
{
    for(int i=0;i<n.size();i++)
		num.push_back(n[i]-'0');
		
    return solve(1, 0, num.size(), 0);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string n;
	cin >> n >> k;
	
	cout << calc(n) << endl;

    return 0;
}

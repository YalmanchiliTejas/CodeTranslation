//mangesh2102000

#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int 
#define ld long double
#define pb push_back
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); ++it)
#define F first
#define S second
#define mod 1000000007  

string k;
int d;

int dp[10005][105][2];

int call(int pos,int rem_sum,int f)
{

	//cout << pos << " " << rem_sum << " " << f << " \n";

	if(dp[pos][rem_sum][f] != -1)
		return dp[pos][rem_sum][f];

	if(pos == k.length())
	{
		if(rem_sum == 0)
		{
			return dp[pos][rem_sum][f] = 1;
		}

		return dp[pos][rem_sum][f] = 0;	
	}


	int limit;

	if(f==0)
	{
		limit = k[pos] - '0';
	}
	else
	{
		limit = 9;
	}

	int ans = 0;

	for(int dig=0;dig<=limit;dig++)
	{
		int nf=f,nrem_sum=rem_sum;
		if(f==0 and dig < (k[pos]-'0'))
			nf = 1;

		nrem_sum -= (dig+d);
		nrem_sum %= d;

		ans += call(pos+1,nrem_sum,nf);
		ans %= mod;
	}

	return dp[pos][rem_sum][f] = ans;

}


int func()
{
	memset(dp,-1,sizeof(dp));
	//cout << k << " ";
	int ans = call(0,d,0);
	return ans;
}

void solve(int t)
{
    cin >> k >> d;
    int ans = func();
    ans--;
    ans += mod;
    ans %= mod;
    cout << ans;
    //cout << "Case #" << t << ": ";    
}   


int32_t main()
{
    IOS;
    int t;
    t=1;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }


    return 0;
}
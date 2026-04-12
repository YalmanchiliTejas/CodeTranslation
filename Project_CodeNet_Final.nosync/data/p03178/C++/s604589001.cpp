#include <bits/stdc++.h>
#define int long long
using namespace std;

int d;
vector<int> num;
int dp[10005][105][2];
int mod = 1e9+7;
int calc(int pos,int rem,int f)
{
    if(pos==num.size())
        return (rem==0);

    if(dp[pos][rem][f]!=-1)
        return dp[pos][rem][f];
    
    int lim=0,res=0;
    if(f==0)
        lim = num[pos];
    else 
        lim = 9;

    for(int i=0;i<=lim;i++)
    {
        int nf = f;
        int nrem = (rem+i)%d;
        if(i<lim)
            nf = 1;
        res = ( res+calc(pos+1,nrem,nf) )%mod;
    }

    return (dp[pos][rem][f] = res);
}

int solve(string x)
{
	for(int i=0;i<x.length();i++)
		num.push_back(x[i]-'0');
	memset(dp,-1,sizeof(dp));
    return calc(0,0,0);
}

int32_t main()
{
	string k;
	cin>>k>>d;
	cout<<(solve(k)-1LL+mod)%mod<<endl;
	return 0;	
}
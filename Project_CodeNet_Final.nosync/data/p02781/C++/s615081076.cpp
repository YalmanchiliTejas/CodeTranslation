#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
ll dp[105][5];

ll dfs(int pos,int state,bool lead,bool limit)
{
    if(pos==-1) 
		if (state == 0) return 1;
		else return 0;
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
    if (state < 0)
    	return 0;
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++) {
    	if (i)
        	ans+=dfs(pos-1,state-1,lead && i==0,limit && i==a[pos]);
        else
        	ans+=dfs(pos-1,state,lead && i==0,limit && i==a[pos]);
    }
    if(!limit && !lead) dp[pos][state]=ans;
    return ans;
}

ll solve(string s, int k)
{
 	int pos = s.size();
	for (int i = 0; i < pos; i++) {
		a[i] = s[pos - i - 1] - '0';
	}
    return dfs(pos-1,k,true,true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛
}

int main()
{
	string s; int k;
	cin >> s >> k;
	memset(dp,-1,sizeof(dp));
	cout << solve(s, k);
	return 0;
}
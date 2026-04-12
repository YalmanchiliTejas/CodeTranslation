#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxlen=1e4+5;
const int maxd=105;
const ll mod=1e9+7;
ll num[5][maxd][maxlen];
void fl()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int main()
{
//    fl();
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string ss;
	cin>>ss;
	ss="_"+ss;
	int len=(int)ss.length()-1;
	int d;
	cin>>d;
	num[1][0][0]=1;
	for(int i=1;i<=len;i++)
	{
		int present=ss[i]-'0';
		for(int r=0;r<d;r++)
			for(int cur=0;cur<=9;cur++)
			{
				int delta=(r-cur+d*10)%d;
				if(cur<present)
					num[0][r][i]=(num[0][r][i]+num[1][delta][i-1]+num[0][delta][i-1])%mod;
				else if(cur==present)
				{
					num[0][r][i]=(num[0][r][i]+num[0][delta][i-1])%mod;
					num[1][r][i]=(num[1][r][i]+num[1][delta][i-1])%mod;
				}
				else 
					num[0][r][i]=(num[0][r][i]+num[0][delta][i-1])%mod;
			}
	}
	ll ans=(num[0][0][len]+num[1][0][len]-1+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}

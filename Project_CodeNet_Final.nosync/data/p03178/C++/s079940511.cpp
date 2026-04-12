#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const ll INF = 1e9;
inline ll read(){
	ll X = 0,w = 0 ;
	char ch = 0;
	while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
	return w ? -X : X;
}

ll dp[10000005];
ll mod=1e9+7;
ll dp2[10000005];
int main() 
{
	string s;
	cin>>s;
	ll d;
	cin>>d;
	dp2[0]=1;
	for(ll i=0;i<s.size();i++)
	{
		ll p=s[i]-'0';
		for(ll j=0;j<d;j++)
		{
			for(ll k=0;k<p;k++)
			{
				dp[(i+1)*100+(j+k)%d]+=dp[i*100+j]+dp2[i*100+j];
			}
			dp[(i+1)*100+(j+p)%d]+=dp[i*100+j];
			dp2[(i+1)*100+(j+p)%d]+=dp2[i*100+j];
			for(ll k=p+1;k<10;k++)
			{
				dp[(i+1)*100+(j+k)%d]+=dp[i*100+j];
			}
		}
		for(ll j=0;j<d;j++)
		{
			dp[(i+1)*100+j]%=mod;
			dp2[(i+1)*100+j]%=mod;
		}
	}
	ll ans=dp[s.size()*100]+dp2[s.size()*100]+mod-1;
	cout<<ans%mod<<endl;
    return 0;
}
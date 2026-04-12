#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
map<ll,ll> d;
long long N,per[51],K,peti[51],cnt,ans;
vector<ll> r;
int main()
{
	cin >> N >> K;
	per[0]=1;
	peti[0]=2;
	for(int i=1; i<=N; i++)
	{
		per[i]=per[i-1]*2+3;
		peti[i]=peti[i-1]*2;
		peti[i-1]--;
	}
	peti[N]--;
	cnt=N;
	
	while(K>0)
	{
		if(K>=per[cnt])
		{
			if(K==per[cnt])
			K-=per[cnt],ans+=peti[cnt];
			else
			{
				K-=per[cnt]+1,ans+=peti[cnt]+1;
			}
		}
		else
		cnt--,K--;
	}
	
	cout << ans;
}
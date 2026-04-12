#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
//#include<unordered_map>
using namespace std;
#define ll long long
#define dd cout<<endl
const long long int inf = 1e18+7;


inline ll int max(ll int a,ll int b) { return a>b?a:b; }
inline ll int min(ll int a,ll int b) { return a<b?a:b; }

const int mod = 1e9+7;
const int maxn=2e5+10;
ll num[maxn];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>num[i];
		
		ll sum=0,pre=0;
		
		for(int i=0;i<n;i++)
		{
			sum+=(pre%mod*num[i]%mod);
			sum%=mod;
			pre+=num[i];
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}

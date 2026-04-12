#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cout<<"->"<<#x<<" : "<<x<<endl;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c)) 
typedef long long ll;
typedef unsigned long long llu;
const double PI = 2*acos(0.0);
#define int long long
signed main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int h[n];
	for(int i=0;i<n;i++)cin>>h[i];
	int res = 0;
	for(int i=0;i<n;i++)
	{
		bool v = 1;
		for(int j=0;j<i;j++)
			if(h[j]>h[i])
				v=0;
		res+=(v&1);
	}	
	cout<<res<<endl;
	return 0;
}
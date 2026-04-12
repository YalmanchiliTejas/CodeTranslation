#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N) cin>>A[i];
	vector<ll> dp;
	for(int a : A)
	{
		if(dp.size()==0||dp[dp.size()-1]>=a)
		{
			dp.push_back(a);
		}
		else
		{
			int head=-1;
			int tail=dp.size();
			while(tail-head>1)
			{
				int mid=head+(tail-head)/2;
				if(dp[mid]<a)
				{
					tail=mid;
				}
				else
				{
					head=mid;
				}
			}
			dp[tail]=a;
		}
	}
	cout<<dp.size()<<endl;
	return 0;
}

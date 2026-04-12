#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
ll N,K;
int main()
{
	ll res=0,maxy;
	cin>>N>>K;
	if (K==0)cout<<N*N<<endl;
	else
	{
		for (ll i=K;i<N;i++)
		{
			res+=N-i;
			res+=(N/(i+1)-1)*(i-K+1);
			//cout<<N-i<<" "<<(N/(i+1)-1)*(i-K+1)<<" "<<max(N%(i+1)-K+1,(ll)0)<<endl;
			if (N%(i+1)!=0)res+=max(N%(i+1)-K+1,(ll)0);
		}
		cout<<res<<endl;
	}
	return 0;
}

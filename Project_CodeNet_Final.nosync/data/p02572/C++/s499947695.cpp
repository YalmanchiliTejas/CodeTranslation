#include <iostream>
#include <fstream>
#include <cstring>



#define rep(a) for(int i=0;i<a;i++)
#define E	<<endl;
#define Mode 1000000007
#define F freopen("in.txt","r",stdin);
using namespace std;

int main()
{
	//F;
	int ar[200005];
	long long tem[200005];
	int n;
	cin>>n;
	rep(n) cin>>ar[i];

	long long sum=0;
	rep(n)
	{
		sum+=ar[i];
		tem[i]=sum;
	}
	long long ans=0;
	rep(n-1)
	{
		long long tempsum=tem[n-1]-tem[i];
		tempsum%=Mode;

		//cout<<"just adition "<<tempsum<<endl;

		tempsum*=ar[i];

		tempsum%=Mode;

		ans+=tempsum;
		ans%=Mode;
	}
	cout<<ans<<endl;
	return 0;
}
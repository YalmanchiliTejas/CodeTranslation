#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define loopj(n) for(int j=0;j<n;j++)
#define loopi(a,b,k) for(int i=a;i<b;i=i+k)
#define  deb(x) cout<<#x<<"  "<<x<<endl
#define sync std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main()
{
	int n{0};
	cin>>n;
	ll a[n];
	ll sum=0;
	loopj(n)
	{
		cin>>a[j];
		sum+=a[j];
	}
	ll k=1e9+7;
	ll sum2=0;
	loopj(n)
	{
		sum=sum-a[j];
		
		sum2=((sum2%k)+((a[j]%k)*(sum%k)))%k;
	}
	cout<<sum2;
}
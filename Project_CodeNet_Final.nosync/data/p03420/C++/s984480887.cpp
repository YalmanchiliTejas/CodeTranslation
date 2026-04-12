#include<bits/stdc++.h>
#define ll long long
ll n,k,ans;
using namespace std;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}
	for(int b=k+1;b<=n;++b)
	{
		ans+=(b-k)*(n/b);
		ans+=max((ll)0,n%b-k+1);
	}
	
	cout<<ans;
}
  
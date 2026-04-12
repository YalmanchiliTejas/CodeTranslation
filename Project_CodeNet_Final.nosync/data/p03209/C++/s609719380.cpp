/* ****GT_18**** */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005
long long int calc(ll x,ll n,ll *pati,ll * len)
{
	//cout<<x<<n<<endl;
	if(n==0 && x==1)
		return 1;
	if(x<2 || n<0)
		return 0;
	if(x<=(len[n]-1)/2)
		return calc(x-1,n-1,pati,len);
	else if(x==len[n])
		return pati[n];
		return pati[n-1]+1+calc(x-(len[n]+1)/2,n-1,pati,len);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		long long int n,x,i,pati[55],len[55];
		pati[0]=1;
		len[0]=1;

		cin>>n>>x;
		for(i=1;i<=n;i++)
		{
			pati[i]=2*pati[i-1]+1;
			len[i]=2*len[i-1]+3;
		}
		
		//cout<<len[50]<<endl;
		//cout<<pati[50]<<endl;
		cout<<calc(x,n,pati,len)<<endl;;

	}
	return 0;
}
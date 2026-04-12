#include <bits/stdc++.h>
 using namespace  std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const double pi=3.1415926535897932384626433832;
const long long mod=1e9+7;
//long long primeset[5000000]={};
typedef complex<double> cd;
typedef long long ll;
typedef double ld;
//#define For(i,0,n) for(long long i = 0 ; i<n ;i++) 
cd fast_exp(cd a, long long b)
{
	if (b == 0)
		return 1;
	
	cd res = fast_exp(a, b / 2);
		
	res = res * res;
	
	if (b % 2 == 1)
		res = res * a;
	
	return res;
}

long long fastexpon(long long a,long long b,long long mod)
{
	if(b==0)
		return 1;
	
	long long res=fastexpon(a,b/2,mod);
	
	res=(res*res)%mod;
	if(b%2==1)
		res= (res * a)%mod;

	return res;
}


//template ends here

ll n;
const ll N=3000;
ll a[N];
ll dp[N][N]={};
ll assigndp[N][N]={};
ll max_x_y(ll l, ll r)
{

	if(assigndp[l][r]!=0)
		return dp[l][r];
	if(l==r)
	return a[r];

	else
	{
		ll c1=a[l]-max_x_y(l+1,r);
		ll c2=a[r]-max_x_y(l,r-1);

		assigndp[l][r]=1;
		dp[l][r]=max(c1,c2);
		return dp[l][r];
	}
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(ll i=0 ;i<n; i++)
		cin>>a[i];
	cout<<max_x_y(0,n-1)<<'\n';



	
	//cout<<'\n'<<"time endslapsed: "<<clock()*1000.0 / CLOCKS_PER_SEC<<" ms"<<'\n';
	return 0;
}
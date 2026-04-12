//To debug :  g++ -g file.cpp -o code
//cout<<setprecision(p)<<fixed<<var
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for(i=a;i<n;++i)
#define irep(i,n,a) for(i=n;i>a;--i)
#define mod 1000000007
#define pb push_back
#define big 9223372036854775807;
#define big1 LONG_MAX
#define big2 INT_MAX
#define big3 1000000000
#define sma1 LONG_MIN
#define sma2 INT_MIN
#define sma3 -1000000000;
#define mp make_pair
#define dub double
#define ivec vector<int>
#define lvec vector<long long>
#define cvec vector<char>
#define svec vector<string>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);


ll a[2][3001][3001];
ll v[3001];
ll n;

ll fun(ll p,ll l,ll r,ll sum)
{

	//this player can either choose l or r
	if(l>r)
	{
		return sum;
	}
	else if(a[p][l][r]!=-1)
	{
		return (sum - a[p][l][r]);
	}
	else if(l==r)
	{
		a[p][l][r] = v[l];
		return (sum - v[l]);
	}
	else
	{
		a[p][l][r] = max(fun(1-p,l+1,r,sum-v[l])+v[l],fun(1-p,l,r-1,sum-v[r])+v[r]);;

		return (sum-a[p][l][r]);
	}

}


int main()
{

	memset(a,-1,sizeof(a));
	ll i,n;
	ll sum = 0,ans1,ans2;

	cin>>n;

	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		sum+=v[i];
	}

	//taro (0) will start
	//jiro (1) next

	ans1 = max(fun(1,2,n,sum-v[1])+v[1],fun(1,1,n-1,sum-v[n])+v[n]); //taro can choose either 1st or nth and then
									// jiro will move
	

	//cout<<ans1<<"\n";

	//cout<<sum<<"\n";

	cout<<2*ans1-sum<<"\n";




	return 0;
}
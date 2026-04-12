#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("myfile.in","r",stdin);freopen ("myfile.out","w",stdout);
#define mod 1000000007
#define fs(x,y) for(int i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

ll n,m,ar[N],sum,mk;


int main()
{
	fast;
	cin>>n;
	fo(i,1,n)
	{
		ll a;
		cin>>a;
		mk=max(mk,a);
		if(a>=mk)
			sum++;
	}
	cout<<sum;

}
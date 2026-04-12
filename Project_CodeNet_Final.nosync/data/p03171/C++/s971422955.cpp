#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define endl "\n" 
#define all(c) c.begin(),c.end()
#define present(c,element) (c.find(element)!=c.end())
#define cpresent(c,element) (find(c,element)!=c.end())
#define foo(i,a,b) for(int i=a;i<int(b);i++)
#define tr(i,a) for(auto i:a)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
const double PI=acos(-1);
const ll mod=1e9+7;



int32_t main()
{
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

int test=1;
//cin>>test;
while(test--)
{
	int n;
	cin>>n;
	vi a(n);
	foo(i,0,n)cin>>a[i];
	ll dp[n][n]={0};	
	for(int l=n-1;l>=0;l--)
	{
		for(int r=l;r<n;r++)
		{
			if(l==r)dp[l][r]=a[l];
			else dp[l][r]=max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
		}
	}
	//foo(i,0,n){foo(j,0,n)cout<<dp[i][j]<<" ";cout<<endl;}
	cout<<dp[0][n-1]<<endl;
}
return 0;
}









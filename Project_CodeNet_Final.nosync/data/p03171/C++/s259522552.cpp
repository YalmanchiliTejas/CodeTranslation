#include <bits/stdc++.h>
using namespace std;
 
#define EPS (1e-9)
#define ll long long int
#define ull unsigned long long
#define pi (acos(-1.0))
#define endl "\n"
#define all(v) v.begin(),v.end()
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define precise(n) cout << fixed << setprecision(n)
#define show(a) cout << (#a) << " is " << (a) << endl;
#define pcase cout<<"Case "<<++cs<<": "
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
const int mod=1e9+7;
const int mx=1e5+10;
 ll inf=1e14+5;
ll binpow(ll base, ll exp){ll res = 1;while(1){ if(exp&1) res*=base;exp>>=1;if(!exp)break;base*=base;}return res;}
ll dp[3005][3005];
vector< ll > v(3005);
int n,m,k;
ll func(int i,int j)
{
	//cout << "called "<< i << " and " <<j << endl; 
	if(i>n || j<1) return 0;
	if(i==j) return dp[i][j]=v[i];
	if(dp[i][j]!=inf) return dp[i][j];
	
	return dp[i][j]=max(v[i]-func(i+1,j),v[j]-func(i,j-1));
}
int main()
{
	FAST;
	
	cin >> n;
	
	for (int i=1;i<=n;i++)
	{
		cin >> v[i];
		
	}
	
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			dp[i][j]=inf;
		}
	}
	//for (int i=0;i<=n;i++)
	//{
		//for (int j=0;j<=n;j++)
		//{
			//cout << "dp["<<i<< "]["<<j <<"] = " << dp[i][j] << endl;
		//}
		
	//}
	
	
		
		cout << func(1,n) << endl;
	
	
	
	
	return 0;
}

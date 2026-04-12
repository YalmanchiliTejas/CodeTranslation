#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
using namespace std;

ll dp[3001][3001][2];
vector<int> a;

ll fun(int l,int r,int c){
	if(r<l)
		return 0;
	ll &ans = dp[l][r][c];
	if(dp[l][r][c]!=1e17)
		return dp[l][r][c];

	if(!c)
		ans = max(a[l]+fun(l+1,r,!c),a[r]+fun(l,r-1,!c));
	else
		ans = min(-a[l]+fun(l+1,r,!c),-a[r]+fun(l,r-1,!c));

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	for(int i=0;i<3001;++i)
		for(int j=0;j<3001;++j)
			dp[i][j][0]=dp[i][j][1]=1e17;
	int n;
	cin>>n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<fun(0,n-1,0);

	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}
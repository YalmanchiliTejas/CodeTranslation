#include<bits/stdc++.h>
using namespace std;
#define ll long long
	#define infl 		9223372036854775807
	#define int		long long
const int NN=3005;
int ans[NN][NN]={}, a[NN]={};

int minimax(int l, int r, bool ismax){
	//cout<<l<<" "<<r<<" "<<ismax<<endl;
	if(ans[l][r]!=infl)
		{return ans[l][r];}

	if(l > r)
		return ans[l][r] = 0;
	if(r==l){
		if(ismax) return (ans[l][r] = a[l]); else return (ans[l][r] = -a[l]);
	}

	if(ismax)
	{
		return ans[l][r] = max(a[l] + minimax(l+1, r, false), a[r] + minimax(l, r-1, false));
	}
	else
	{
		return ans[l][r] = min(-a[l] + minimax(l+1, r, true), -a[r] + minimax(l, r-1, true));
	}

}

signed main()
{
	int n;
	cin>>n;
	for(int i=0; i<NN; ++i)for(int j=0; j<NN; ++j)ans[i][j]=infl;
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	minimax(0, n-1, true);
	/*for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			if(i>j)
				cout<<"* ";
			else cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans[0][n-1];
	return 0;
}
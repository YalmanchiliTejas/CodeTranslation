#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> A;
int pd[3002][3002][2];
int dp(int l,int r,bool fl){
	if(r<l) return 0;
	if(pd[l][r][fl]!=-1) return pd[l][r][fl];
	if(fl)
		return pd[l][r][fl] = max(A[l]+dp(l+1,r,!fl),A[r]+dp(l,r-1,!fl));
	return pd[l][r][fl] = min(-A[l]+dp(l+1,r,!fl),-A[r]+dp(l,r-1,!fl));
}

int32_t main(){
	memset(pd,-1,sizeof pd);
	int n;
	cin >> n;
	A = vector<int> (n);
	for(auto &a:A) cin >> a;
	cout << dp(0,n-1,true) << '\n';
}
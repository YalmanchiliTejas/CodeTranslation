#include <bits/stdc++.h>
using namespace std;

#define N (int)3e3+5
#define f1 first
#define s2 second
#define pb push_back
#define ll long long
#define mod (int)1e9
#define INF 99999999
#define	ull unsigned long long
#define all(a) a.begin(),a.end()
#define fri(a) freopen((a),"r",stdin);
#define fro(a) freopen((a),"w",stdout);

ll n,dizi[N],dp[N][N];

ll dpf(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	if(l>r)return 0;
	ll ans1=dpf(l+1,r);
	ll ans2=dpf(l,r-1);
	return dp[l][r]=max(dizi[l]-ans1,dizi[r]-ans2);
}

int main(){
	//fri("in.txt");
	//fro("out.txt");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dizi[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dpf(1,n);
	return 0;
}
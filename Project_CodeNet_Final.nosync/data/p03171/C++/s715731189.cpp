#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


/*

*/


ll n,a[3010],largest[3010][3010],smallest[3010][3010];

ll f(bool player,ll l,ll r){
	if(l>r)return 0;
	if(player){
		if(largest[l][r]!=-1e18){
			return largest[l][r];
		}else{
			return largest[l][r] = max(f(!player,l+1,r)+a[l], f(!player,l,r-1)+a[r]);
		}
	}else{
		if(smallest[l][r]!=1e18){
			return smallest[l][r];
		}else{
			return smallest[l][r] = min(f(!player,l+1,r)-a[l], f(!player,l,r-1)-a[r]);
		}
	}
	return 0;
}

int main(void){
	cin>>n;
	rep(i,n)cin>>a[i];
	//
	rep(i,n)rep(j,n)largest[i][j]=-1e18;
	rep(i,n)rep(j,n)smallest[i][j]=1e18;
	//
	cout<<f(true,0,n-1)<<endl;
	return 0;
}
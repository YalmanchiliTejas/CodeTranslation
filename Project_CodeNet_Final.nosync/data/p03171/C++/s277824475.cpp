
// Target Expert 

/*
 * Author    : raj1307 - Raj Singh
 * Institute : Jalpaiguri Government Engineering College
 * Date      : 8.08.19
 */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <iomanip>
#include <memory.h>
#include <assert.h>
using namespace std;


//#define DEBUG
#ifdef DEBUG
#define deb(...) cerr<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cerr<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cerr.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}

#else
#define deb(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#define endl "\n"
#endif

#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fr(i, a, b) for(int i = (a); i < (b); ++i)
#define fb(i, b, a) for(int i = (b); i > (a); --i)
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define rr return 
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
int max(int a,int b){if(a>b) return a; else return b;}
int min(int a,int b){if(a>b) return b; else return a;}

const int mod = 1000*1000*1000+7;
const int INF = 1e18 +5;

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


const int N = 1e5 + 5;
int n;
int a[3002];
int cache[3002][3002][2];

 


int dp(int l,int r,int turn){


 
	if(l>r or l==n or r==-1) return 0;

	int &ans=cache[l][r][turn];

	if(ans!=-1) return ans;



	if(turn==0)
		ans=max(a[l]+dp(l+1,r,turn^1),a[r]+dp(l,r-1,turn^1));
	else
		ans=min(dp(l+1,r,turn^1)-a[l],dp(l,r-1,turn^1)-a[r]);

	return ans;



}



 
void solve(){
 
 
	cin>>n;
	fr(i,0,n) cin>>a[i];

	memset(cache,-1,sizeof(cache));

	cout<<dp(0,n-1,0);




	
	

 
}
 



signed main() {
	fio;

	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--) {
		solve();
	}

	
	return 0;
}

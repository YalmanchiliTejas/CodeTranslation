#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;
vector<vector<LL>> dp;
vector<vector<LL>> fl;
vector<LL> aa;

LL f(int l,int r,int v){
	if(fl[l][r]==1)return dp[l][r];
	if(l==r){
		fl[l][r]=1;
		if(v==0){
			dp[l][r]=aa[l];
		}else{
			dp[l][r]=-aa[l];
		}
		return dp[l][r];
	}
	if(v==0){
		dp[l][r]=max(f(l+1,r,v^1)+aa[l],f(l,r-1,v^1)+aa[r]);
	}else{
		dp[l][r]=min(f(l+1,r,v^1)-aa[l],f(l,r-1,v^1)-aa[r]);
	}
	fl[l][r]=1;
	return dp[l][r];
}

int main(){
	int n;
	cin>>n;
	vector<LL> a(n);
	FOR(i,0,n)cin>>a[i];
	aa=a;
	vector<vector<LL>> dp2=vector<vector<LL>>(n+1,vector<LL>(n+1,0));
	vector<vector<LL>> fl2=vector<vector<LL>>(n+1,vector<LL>(n+1,0));
	dp=dp2;
	fl=fl2;
	cout<<f(0,n-1,0);

    return 0;
}

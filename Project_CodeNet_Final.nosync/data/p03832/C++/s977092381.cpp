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
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

#define MOD 1000000007

int n, a, b, c, d;
vector<lli> k;
vector<vector<lli>> o;
vector<vector<lli>> dp;

void kk(void){
	k.resize(n+1);
	k[0] = 1;
	reg(i, 1, n) k[i] = (k[i-1] * i)%MOD;
	return;
}

lli po(lli ii, lli j){
	lli t[32], ret = 1; t[0] = ii%MOD;
	rep(i, 31) t[i+1] = (t[i]*t[i])%MOD;
	rep(i, 31) if((j>>i)&1) ret = (ret*t[i])%MOD;
	if(ret < 0) cout << ii << " " << j << endl;
	return ret;
}

void rev(void){
	vector<lli> w(n+1);
	rep(i, n+1) w[i] = po(k[i], MOD-2);
	rep(i, n+1) rep(l, n+1) o[l][i] = (po(k[l], MOD-1-i)*w[i])%MOD;
	return;
}

lli f(lli l, lli r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == b+1){
		if(r == 0) return dp[l][r] = k[n];
		else return dp[l][r] = 0;
	}else{
		lli ret = f(l+1, r);
		reg(i, c, min(d, int(r/l))) ret += (f(l+1, r - i*l)*o[l][i])%MOD;
		return dp[l][r] = ret%MOD;
	}
}

int main(void){
	cin >> n >> a >> b >> c >> d;
	dp.assign(n+2, vector<lli>(n+2, -1));
	o.assign(n+2, vector<lli>(n+2));
	kk(); rev();
	cout << f(a, n) << endl;	
	return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long lli;
#define MOD 1000000007
lli n,a,b,c,d;
lli dp[1001][1001];
bool bl[1001][1001];


lli exeuclid(lli a,lli aa,lli x,lli xx,lli y,lli yy){
	lli q;
	if(a == 0) return aa > 0 ? xx : -xx;
	q = aa / a;
	return exeuclid(aa - q * a,a,xx - q * x,x,yy - q * y,y);
}

lli invarse(lli x){
    static unordered_map<lli,lli> dp;
    if(dp[x]) return dp[x];
	return dp[x] = (exeuclid(MOD,x,0,1,1,0) + MOD) % MOD;
}


lli factrial(lli x){
	static lli dp[100000];
	if(dp[x]) return dp[x];
	if(x == 0) 	return dp[x] = 1;
				return dp[x] = (factrial(x-1) * x) % MOD;
}
lli pow(lli a,lli n,lli mod = 1000000007){
	lli ret = 1;
	for(;n!=0;n=n>>1){
		if(n&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}
lli f(lli n,lli k,lli x){
    lli ret = factrial(n);ret %= MOD;
    ret *= invarse(factrial(n-x*k));ret %= MOD;
    ret *= invarse(pow(factrial(k),x));ret %= MOD;
    ret *= invarse(factrial(x));ret %= MOD;
    return ret;
}
lli dfs(lli i,lli j){
    if(bl[i][j]) return dp[i][j];
    bl[i][j] = true;
    if(i < a) return dp[i][j] = j ? 0 : 1;
    dp[i][j] = dfs(i-1,j);
    for(lli k = c;k <= d && j-k*i >= 0;k++){
        dp[i][j] += dfs(i-1,j-k*i)*f(j,i,k);
        dp[i][j] %= MOD;
    }
    return dp[i][j];
}
int main(int argc, char const *argv[]) {
    cin >> n >> a >> b >> c >> d;
    cout << dfs(b,n) << endl;
    return 0;
}

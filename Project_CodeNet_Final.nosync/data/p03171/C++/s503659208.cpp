#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
const ll INF=1e15;
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

long long binpows(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  //impar
            res = res * a;
        a = a * a;
        b >>= 1;  // /2
    }
    return res;
}
const int mod=1e9+7;
int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
//CHECAR SE PRECISA DE LONG LONG
int dp[3234][3234][2];
vector<int> v;
int n;
int resolve(int l, int r, bool f){
	if(l==r){
		if(f){
			return v[l];
		}else{
			return 0;
		}
	}
	int &x=dp[l][r][f];
	if(x!=-1){
		return x;
	}

	if(f){
		x=0;
		x=max(x,resolve(l+1,r,!f)+v[l]);
		x=max(x,resolve(l,r-1,!f)+v[r]);
	}else{
		x=INF;
		x=min(x,resolve(l+1,r,!f));
		x=min(x,resolve(l,r-1,!f));
	}
	return x;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	v.resize(n);
	int sum=0;
	for(auto &i: v){
		cin>>i;
		sum+=i;
	}
	cout<<resolve(0,n-1,true)-(sum-resolve(0,n-1,true))<<endl;
}
//revise as variaveis e a ordem nas funções
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
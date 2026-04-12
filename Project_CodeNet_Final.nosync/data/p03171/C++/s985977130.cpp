#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
// template starts
typedef long long int ll;
ll fact(ll n, ll p){
	ll ans = 1;
	for(ll i = 1; i <= n; i++){
		ans *= i;
		ans %= p;
	}
	return ans;
}
ll power(ll x, ll n, ll p){
	ll res = 1;
	if(n == 1) return x%p;
	if(n%2 == 1) res = x%p;

	ll temp = power(x,n/2,p);
	return res*((temp*temp)%p)%p;
}
ll inv(ll a, ll p){
	return power(a,p-2,p);
}
ll nCr(ll n, ll r, ll p){
	if(r > n) return 0;
	ll t1 = fact(n,p);
	ll t2 = inv(fact(r,p),p);
	ll t3 = inv(fact(n-r,p),p);

	return (((t1*t2)%p)*t3)%p;
}
vector<vector<ll> > multiply(vector<vector<ll> > &a, vector<vector<ll> > &b, ll p){
	int r1,c1,r2,c2;
	r1 = a.size(); c1 = a[0].size();
	r2 = b.size(); c2 = b[0].size();

	vector<vector<ll> > result(r1,vector<ll>(c2,0));

	if(c1 != r2) return result;

	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c2; j++){
			for(int k = 0; k < c1; k++){
				result[i][j] += a[i][k]*b[k][j];
				result[i][j] %= p;
			}
		}
	}
	return result;
}

vector<vector<ll> > power(vector<vector<ll> >&a,ll n, ll p){
	int r = a.size();
	vector<vector<ll> > result(r,vector<ll>(r,0));
	for(int i = 0; i < r; i++) result[i][i] = 1;

	while(n > 0){
		if(n%2 == 1){
			result = multiply(result,a,p);
		}
		n /= 2;
		a = multiply(a,a,p);
	}
	return result;
}
// template ends here
vector<vector<ll> > dp;
ll f(ll start, ll end, vector<ll> &vec){
	if(dp[start][end] != -1) return dp[start][end];
	
	if(start == end) return vec[start];
	if(start+1 == end) return max(vec[start],vec[end]);
	
	ll t1= vec[start] + min(f(start+2,end,vec),f(start+1,end-1,vec));
	ll t2 = vec[end]  + min(f(start+1,end-1,vec), f(start,end-2,vec));
	
	dp[start][end] = max(t1,t2);
	return max(t1,t2);
}

void solve(){
	// code starts from he
	ll N, sum = 0;
	cin >> N;
	vector<ll> vec(N);
	
	dp.resize(N);
	forf(i,0,N){
		forf(j,0,N) dp[i].pb(-1);
	}
	forf(i,0,N){
		cin >> vec[i];
		sum += vec[i];
	}
	
	ll ans = 2*f(0,N-1,vec) -sum;
	cout << ans << endl;
}

int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	//cin >> T;
	T = 1;
	while(T--){
		solve();
	}

	return 0;
}

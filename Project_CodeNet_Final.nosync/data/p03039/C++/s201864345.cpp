#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>

#define F_OR(i, a, b, s) for (ll i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
 
int n,m,k;
vector<pair<int,int>> points;

const int nax = 1e6 + 50, mod = 1e9+7;
ll fac[nax*2], fin[nax*2];

ll power(ll a, ll b){
	ll result = 1;
	while(b>0){
		if(b&1) result = (result*a)%mod;
		(a*=a)%=mod;
		b/=2;
	}
	return result;
}

ll inv(ll x){
	ll e = mod -2, r = 1;
	while(e){
		if(e&1) r=r*x%mod;
		x = x*x %mod;
		e>>=1;
	}
	return r;
}

ll ncr(ll a, ll b){
	if(b<0 || b > a) return 0;
	return fac[a] * fin[b] % mod * fin[a-b] % mod;
}




// finding the distance between all pair of points in O(nlogn)
ll dist(){
	ll ans = 0;
	vector<int> x,y;
	FOR(i,1,n+1) FOR(j,1,m+1) x.pb(i);
	FOR(i,1,m+1) FOR(j,1,n+1) y.pb(i);
	
	ll prev_sum = 0;
	FOR(i,1,x.size()){
		ans += ((x[i]-x[i-1])*i + prev_sum)%mod;
		ans %= mod;
		prev_sum += ((x[i]-x[i-1])*i)%mod;
		prev_sum %= mod;
	}

	prev_sum = 0;
	FOR(i,1,y.size()){
		ans += ((y[i]-y[i-1])*i + prev_sum)%mod;
		ans %= mod;
		prev_sum += (y[i]-y[i-1])*i;
		prev_sum %= mod;
	}
	
	return ans;
}
 
// for any pair we can choose the other k-2 points in nm-2 nCr k-2 ways
// meaning this pair occurs in nm-2 nCr k-2 arrangements
// in manhattan x and y are independent
void solve(){
	cin >> n >> m >> k;
	
	//setting up ncr
	fac[0] = 1;
	FOR(i,1,nax*2) fac[i] = fac[i-1] * i % mod;
	fin[nax*2-1] = inv(fac[nax*2-1]);
	for(int i = nax*2-2; i>=0; --i) fin[i] = fin[i+1]*(i+1)%mod;
	
	cout << (dist() * ncr(n*m-2,k-2))%mod;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 

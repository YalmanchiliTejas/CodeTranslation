#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e18;
 
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
 
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>vector<T>
make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}

void pv(vector<int>&v){
	for(int i = 0;i<v.size();i++){
		if(i)cout<<' ';
		cout<<v[i];
	}
	cout<<endl;
}

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long H(int n,int k){
    return COM(n+k-1,k);
}

signed main()
{
	IOS();
	COMinit();
	int N,M,K;
	cin>>N>>M>>K;
	int t = COM(N*M-2,K-2);
	int s = 0;
	rep(i,1,N){
		(s += (N - i) * i)%=MOD;
	}
	(t *= (M * M) % MOD)%=MOD;
	(t *= s)%=MOD;
	int ans = t;
	swap(N,M);
	t = COM(N*M-2,K-2);
	s = 0;
	rep(i,1,N){
		(s += (N - i) * i)%=MOD;
	}
	(t *= (M * M) % MOD)%=MOD;
	(t *= s)%=MOD;
	cout<<(ans+t)%MOD<<endl;
}

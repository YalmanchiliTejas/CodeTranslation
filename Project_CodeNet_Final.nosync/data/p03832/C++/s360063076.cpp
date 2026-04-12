#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


const int MAX_N = 1010;
vec nCm(MAX_N+1,0);
vec fact(MAX_N+1,0),fact_inv(MAX_N+1,0);

ll fastpow(ll a, ll pw) {
	ll res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return res;
}
void makefact(ll n){//MODは素数かつnより大きい
    ll ans = 1;
    fact.at(0) = ans;
    fact_inv.at(0) = ans;
    reps(i,1,n+1){
        (ans *= i)%=MOD;
        fact.at(i) = ans;
        fact_inv.at(i) = fastpow(ans,MOD-2);
    }
    return;
}
ll C, D;
mat memo(1001, vec(1001,-1));
ll dfs(ll rest, ll mem){
    if(mem == B + 1) return (rest == 0 ? 1 : 0);
    if(rest < 0) return 0;
    if(memo[rest][mem] != -1) return memo[rest][mem];
    ll ans = dfs(rest, mem + 1), alpha = fastpow(fact_inv.at(mem), C);
    for(int g_num = C; rest >= g_num * mem && g_num <= D; ++g_num){
        (ans += ((dfs(rest - g_num * mem, mem + 1) * alpha)%MOD)*fact_inv.at(g_num))%=MOD;
        (alpha *= fact_inv.at(mem))%=MOD;
    }
    memo[rest][mem] = ans;
    return ans;
}

int main() {
    cin>>N>>A>>B>>C>>D;
    makefact(N);
    ll ans = dfs(N, A);
    reps(i,1,N+1) (ans *= i)%=MOD;
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const int N_MAX = 200010;
ll Per[N_MAX] = {}; // n!
ll Per_inv[N_MAX] = {}; //(n!)^-1

ll nCr(ll n, ll r){
    if(n<r) return 0;
 
    if (n == r || r == 0)
        return 1;
    else
        return Per[n] * Per_inv[n-r] % mod * Per_inv[r] % mod;  
}
 
// a^b mod p
ll mod_pow(ll a, ll b){
    if(b==0) return 1;
 
    // 肩が奇数
    if(b%2==1){
        return a * mod_pow(a, b-1) % mod;
    }
    else{
        return mod_pow(a*a % mod, b/2) % mod;
    }
}

void prepare_nCr(){
    // nCr高速化準備
    Per[1] = 1;
    FOR(i, 2, N_MAX){
        Per[i] = i * Per[i-1] % mod;
    }
    Per_inv[1] = 1;
    FOR(i, 2, N_MAX){
        Per_inv[i] = mod_pow(Per[i], 1000000005);
    }
}

void vprint(vector<ll> A){
    ll L = A.size();
    FOR(i, 0, L){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, M, K;
    cin >> N >> M >> K;
    prepare_nCr();

    ll ans = 0;

    // x方向
    FOR(dx, 1, N){
        ans += dx * (N-dx) % mod * M % mod * M % mod * nCr(M*N-2, K-2) % mod;
        ans %= mod;
    }

    // y
    FOR(dy, 1, M){        
        ans += dy * (M-dy) % mod * N % mod * N % mod * nCr(M*N-2, K-2) % mod;
        ans %= mod;
    }

    p(ans);
    
    return 0;
}
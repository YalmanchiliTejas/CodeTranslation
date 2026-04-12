#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 998244353
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define Nmax 10000005
const long double PI = acos(-1);

int n,x;
int A[Nmax],S[Nmax],B[Nmax],S2[Nmax], P2[Nmax];

template<typename T = long long>
T _pow(T a, T b){
    T ans = 1;
    for (; b; b >>= 1){
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

long long P[Nmax], inv[Nmax];
template<typename T = long long>
T comb(T n, T m){
    if (P[1] == 0) cerr << "Apeleaza functia prec!\n";
    return P[n] * inv[m] % MOD * inv[n-m] % MOD;
}

template<typename T = long long>
inline void add(T &a, T b){
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

void prec(int n = Nmax-1){
    P[0] = inv[0] = 1;
    for (int i=1;i<=n;i++){
        P[i] = P[i-1] * i % MOD;
        inv[i] = _pow(P[i], MOD - 2LL);
    }
}

int main(){
    ios::sync_with_stdio(false);
    prec();

    cin >> n;
    int x = n / 2;

    P2[0] = 1;
    for (int i=1;i<=n;i++){
        P2[i] = 1LL * P2[i-1] * 2 % MOD;
    }

    for (int i=1;i<=x;i++){
        A[i] = comb(x,i);
    }
    for (int i=x;i>=1;i--){
        add(S[i], S[i+1]);
        add(S[i], A[i]);
        S2[i] = (S2[i+1] + 1LL * A[i] * P2[x-i]) % MOD;
    }

    int ans = 0;
    for (int i=1;i<=x;i++){
        int y = (x+1) - i;
        // dbg(i,A[i],P2[x-i],S2[y]);
        ans = (ans + 1LL * A[i] * P2[x-i] % MOD * S2[y]) % MOD;
    }

        // dbg(ans);
    ans = ans * 2 % MOD;
    ans = (1LL * _pow(3LL,1LL*n) - ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
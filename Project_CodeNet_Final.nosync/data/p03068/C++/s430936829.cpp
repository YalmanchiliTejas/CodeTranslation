#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define double long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mt make_tuple
#define gcd __gcd
#define fir first
#define sec second
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sortv(v) sort(all(v))
#define sortg(v) sort(all(v), greater<int>())
#define countv(v, c) count(all(v), c)
#define lb(v, c) lower_bound((v).begin(), (v).end(), c) - (v).begin()
#define ub(v, c) upper_bound((v).begin(), (v).end(), c) - (v).begin()
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
void in(){}
template<typename F, typename... R>
bool in(F& f, R&... r){
    if(cin >> f){
        in(r...);
        return true;
    }else{
        return false;
    }
}
#define inv(x) each(i, x) in(i)
#define out(x) cout << (x)
#define space() cout << " "
#define indent() cout << '\n'
void print(){}
template<typename F, typename... R>
void print(F f, R... r){out(f), indent(), print(r...);}
#define printv(x) each(i, x) out(i), space(); indent()
#define debughead(x) cerr << "Line " << __LINE__ << ": " << #x << ": "
#define debugout(x) cerr << (x) << " "
#define debugindent() cerr << '\n'
#define debug(x) debughead(x), debugout(x), debugindent()
#define YN(x) out((x) ? "YES" : "NO"), indent()
#define Yn(x) out((x) ? "Yes" : "No"), indent()
#define yn(x) out((x) ? "yes" : "no"), indent()
const int INF = 1e18, MOD = 1e9 + 7, LIMIT = 100001, S_LIMIT = 101;
const double EPS = 1e-15, PI = acos(-1);
const int dx[] = {0, 0, 1, 0, -1, -1, 1, 1, -1}, dy[] = {0, -1, 0, 1, 0, -1, -1, 1, 1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int g[S_LIMIT][S_LIMIT] = {};
int modpow(int x, int n){return n < 2 ? x : modpow(x * x, n / 2) * (n % 2 ? x : 1) % MOD;}
int modfact(int n){return n < 2 ? 1 : modfact(n - 1) * n % MOD;}
int modcomb(int n, int r){return modfact(n) * modpow(modfact(r), MOD - 2) % MOD * modpow(modfact(n - r), MOD - 2) % MOD;}
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
int lcm(int a, int b){return a / gcd(a, b) * b;}
int factorial(int a){return a < 2 ? 1 : factorial(a - 1) * a;}
int summation(int a){return a < 1 ? 0 : (a * a + a) / 2;}
int combination(int n, int r){
    int res = 1;
    rep(i, 1, r + 1){
        res *= n--, res /= i;
    }
    return res;
}
bool isPrime(int n){
    rep(i, 2, sqrt(n) + 1){
        if(i > 3){
            i++;
        }
        if(!(n % i)){
            return false;
        }
    }
    return true;
}
void warshall(int n){
    rep(i, n){
        rep(j, n){
            rep(k, n){
                chmin(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
}
vector<int> divisor(int n){
    vector<int> ans;
    rep(i, 1, sqrt(n) + 1){
        if(!(n % i)){
            ans.pb(i);
            if(i * i < n){
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
map<int, int> factorization(int n){
    map<int, int> ans;
    rep(i, 2, sqrt(n) + 1){
        if(i > 3){
            i++;
        }
        while(!(n%i)){
            ans[i]++, n /= i;
        }
    }
    if(n > 1){
        ans[n]++;
    }
    return ans;
}
struct UF{
    vector<int> t;
    UF(int size): t(size, -1){}
    int root(int x){return t[x] < 0 ? x : t[x] = root(t[x]);}
    int size(int x){return -t[root(x)];}
    bool isSame(int x, int y){return root(x) == root(y);}
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x != y){
            if(t[y] < t[x]){
                swap(x, y)
            ;}
            t[x] += t[y], t[y] = x;
        }
        return x != y;
    }
};
int n, k, tmp, res = 0;
string s, t;
main(){
    INCANT;
    in(n, s, k);
    each(c, s){
        if(c != s[k - 1]){
            out('*');
        }else{
            out(c);
        }
    }
}

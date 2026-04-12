#include <bits/stdc++.h>
using namespace std;
using ll = long long; using P = pair<int,int>;
using vl = vector<ll>; using vvl = vector<vl>;
#define mp make_pair
#define pb push_back
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,n) for (int i=(n-1);i >= 0;i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)((v).size())
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))
#define Sort(v) sort(all(v))
#define Rev(v) reverse(all(v))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << H << " ";
    debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
    for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
const int dx[8] = {1,0,-1,0,1,1,-1,-1}; const int dy[8] = {0,1,0,-1,1,1,-1,-1};

ll n;
ll a[3000];
bool flag[3000][3000];
ll dp[3000][3000]; // dp[i][j] = [i, j]が残ってるときから始めた最大スコア

ll dfs(ll l, ll r) {
    if(flag[l][r]) return dp[l][r];
    flag[l][r] = true;
    if(l == r) return dp[l][r] = a[l];
    return dp[l][r] = max(a[l]-dfs(l+1, r), a[r]-dfs(l, r-1));
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    rep(i,n) cin >> a[i];
    cout << dfs(0, n-1) << endl;
}
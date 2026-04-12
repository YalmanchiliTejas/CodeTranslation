#include <bits/stdc++.h>
using namespace std;
#ifdef __DEBUG__
    void debug_out() { cerr << endl; } 
    template <typename Head, typename... Tail>
    void debug_out(Head H, Tail... T) {cerr << " " << H; debug_out(T...);}
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 
#endif

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 1,-1, 1,-1};
int dy[]={0, 1, 0, -1, 1, 1,-1,-1};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);

inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const deque<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

ll N,X,M;
inline void input(){
    fast_io();
    cin >> N >> X >> M;
}

inline int solve(){
    ll ans = 0;
    vector<ll> pwX(M,0);
    for (ll i = 0; i < M; i++)
    {
        pwX[i] = (i*i)%M;
    }
    ll x = X;
    vector<bool> used(M,false);
    ll rest = 0;
    for (int i = 0; i < N; i++)
    {
        if(used[x]) {
            rest = N-i;
            break;
        }
        used[x] = true;
        ans += x;
        x = pwX[x];
        if(x==0) break;
        if(x==1){
            ans += N-1-i;
            break;
        }
    }
    if(rest){
        ll T = 0, Sum = 0;
        ll init = x;
        T++;
        Sum += x;

        x = pwX[x];
        while(x != init && T<rest){
            T++;
            Sum += x;
            x = pwX[x];
        }
        debug(ans,rest,T,Sum);
        ans += 1LL*Sum*(rest/T);
        rest %= T;
        for (int i = 0; i < rest; i++)
        {
            ans += x;
            x = pwX[x];
        }
        debug(ans,rest,T,Sum);
    }
    cout << ans << endl;
    
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}

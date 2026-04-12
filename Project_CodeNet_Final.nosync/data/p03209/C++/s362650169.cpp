#include <bits/stdc++.h>
#ifdef __DEBUG__
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

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

ll N,X;
void input(){
    fast_io();
    cin >> N >> X;
}

vector<ll> sizeBurger,patty;
ll dfs(ll L, ll x){
    if(x<=L) return 0;
    if(sizeBurger[L]==x) return patty[L];
    else if(sizeBurger[L]<x) return 0;
    if(x<=sizeBurger[L-1]+1) return dfs(L-1,x-1);
    else if(x==sizeBurger[L-1]+2) return 1+patty[L-1];
    else if(x<=2*sizeBurger[L-1]+2) return 1+patty[L-1]+dfs(L-1,x-2-sizeBurger[L-1]);
    else return 1+2*patty[L-1];
}

int solve(){
    sizeBurger.assign(N+1,0),patty.assign(N+1,0);
    sizeBurger[0] = 1;
    patty[0] = 1;
    for (int i = 0; i < N; i++)
    {
        sizeBurger[i+1] = 3+2*sizeBurger[i];
        patty[i+1] = 1+2*patty[i];
    }
    cout << dfs(N,X) << endl;

    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/segtree>
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

int N,Q;
vector<int> A;
inline void input(){
    fast_io();
    cin >> N >> Q;
    A = fetch_vec<int>(N);
}

int op(int a, int b){return max(a,b);};
int e(){return -1;}
int target;
bool f(int v) { return v < target; }

inline int solve(){
    atcoder::segtree<int,op,e> sg(A);
    for (int i = 0; i < Q; i++)
    {
        int type,a,b;
        cin >> type >> a >> b;
        if(type==1){
            a--;
            sg.set(a,b);
        }
        else if(type==2){
            a--;
            cout << sg.prod(a,b) << "\n";
        }
        else{
            target = b;
            a--;
            int j = sg.max_right<f>(a)+1;
            cout << j << "\n";
        }

    }
    
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}

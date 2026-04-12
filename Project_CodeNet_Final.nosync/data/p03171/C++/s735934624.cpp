#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#ifdef DEBUG
    #include "debug.hpp"
#endif

using namespace std;

#define all(c) (c).begin(), (c).end()
#define traverse(c, it) for(auto it = (c).begin(); it != (c).end(); it++)
#define rep(i, N) for(int i = 0; i < (N); i++)
#define rep1(i, N) for(int i = 1; i <= (N); i++)
#define rep2(i, s, e) for(int i = (s); i <= (e); i++)
#define rep3(i, s, e, d) for(int i = (s); (d) >= 0 ? i <= (e) : i >= (e); i += (d))
#define pb push_back


#ifdef DEBUG
    #define debug(x...) {dbg::depth++; string dbg_vals = dbg::to_string(x); dbg::depth--; dbg::fprint(__func__, __LINE__, #x, dbg_vals);}
    #define light_debug(x) {dbg::light = 1; dbg::dout << __func__ << ":" << __LINE__ << "  " << #x << " = " << x << endl; dbg::light = 0;}
#else
    #define debug(x...)
    #define light_debug(x) 
#endif

template<typename T>
T& ckmin(T& a, T b){ return a = a > b ? b : a; }

template<typename T>
T& ckmax(T& a, T b){ return a = a < b ? b : a; }

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

namespace ioUtils {

    char vector_delimiter = ' ';

    template<typename T>
    istream& operator >>(istream&, vector<T>&);

    template<typename... Ts>
    istream& operator >>(istream& is, pair<Ts...>& p){
        is >> p.first >> p.second;
        return is;
    }

    template<typename T> 
    istream& operator >>(istream& is, vector<T>& v){
        for(auto& e : v) is >> e;
	       return is;
    }

    template<typename T>
    ostream& operator <<(ostream&, vector<T>&);

    template<typename... Ts>
    ostream& operator <<(ostream& os, pair<Ts...>& p){
        os << p.first << " " << p.second;
        return os;
    }

    template<typename T>
    ostream& operator <<(ostream& os, vector<T>& v){
        for(auto&& e : v) os << e << vector_delimiter;
        return os;   
    }   
}

using namespace ioUtils;


int N;
vi a;
ll dp[3000][3001];
bool ch[3000][3001];

ll rec(int i, int j){
	if(i >= j) return 0;
	if(ch[i][j]) return dp[i][j];
	ch[i][j] = 1;
	if((i ^ j ^ N) & 1) return dp[i][j] = min(rec(i + 1, j) - a[i], rec(i, j - 1) - a[j - 1]);
	else return dp[i][j] = max(rec(i + 1, j) + a[i], rec(i, j - 1) + a[j - 1]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef DEBUG
        freopen("debug", "w", stderr);
    #endif
    
    cin >> N;
    a.resize(N);
    cin >> a;

    cout << rec(0, N) << '\n';
    #ifdef DEBUG
        dbg::dout << "\nExecution time: " << clock() << "ms\n";
    #endif

    return 0;
}

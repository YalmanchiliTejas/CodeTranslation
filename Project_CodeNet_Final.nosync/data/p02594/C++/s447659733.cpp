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


using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef DEBUG
        freopen("debug", "w", stderr);
    #endif
    
    int X;
    cin >> X;
    if(X >= 30)
        cout << "Yes\n";
    else
        cout << "No\n";

    #ifdef DEBUG
        dbg::dout << "\nExecution time: " << clock() << "ms\n";
    #endif

    return 0;
}

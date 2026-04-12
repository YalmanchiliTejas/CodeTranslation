
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

#include <algorithm>
#include <complex>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <bitset>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
#define strtok_r strtok_s
#endif

#define ITER(c)             __typeof__((c).begin())
#define FOREACH(it, c)      for (ITER(c) it=(c).begin(); it != (c).end(); ++it)
#define RITER(c)            __typeof__((c).rbegin())
#define RFOREACH(it, c)     for (RITER(c) it=(c).rbegin(); it != (c).rend(); ++it)
#define REP(i, n)           REPEAT(i, 0, n)
#define RREP(i, n)          RREPEAT(i, 0, n)
#define REPEAT(i, k, n)     for(int i = (k); i < (k+n); ++i)
#define RREPEAT(i, k, n)    for(int i = (k)+(n)-1; i >= (k); --i)
#define FROMTO(i,f,t)       for(int i = f; i < t; i++)
#define ALL(c)              (c).begin(), (c).end()
#define LLPOW(p1,p2)        ((ll)pow((double)(p1), (int)p2))
#define ESIZEOF(A)          (sizeof(A)/sizeof((A)[0]))
#define CIN_NO_SYNC         do { cin.tie(0); ios_base::sync_with_stdio(false); } while(0)
#define GETSTR(p)           fgets((p), sizeof(p), stdin)
#define CHOMP(p)            do{ char *_q = (p) + strlen(p)-1; if(*_q == '\n' || *_q == '\r') *_q = 0; } while(0)
#define FILL(m,v)           memset(m, v, sizeof(m))
#define mp                  make_pair
#define pb                  push_back
template<class _T> _T MAX(_T p1,_T p2){return (p1>p2)?p1:p2;} 
template<class _T> _T MIN(_T p1,_T p2){return (p1<p2)?p1:p2;} 
template <class _Tv> inline string join(_Tv &v,string sep=" "){
    ostringstream s;FOREACH(it,v){if(it!=v.begin())s<<sep;s<<*it;};return s.str();
}

typedef long long ll;
typedef unsigned long long ull;
typedef double D;
typedef complex<D> P;
#define X real()
#define Y imag()
#define EPS (1e-9)
#define DEQ(p1,p2) (abs((p1)-(p2)) < EPS)

#ifdef _DEBUG
template<class _Tv> inline void _prfe(const char *_n,_Tv _c,bool _p=false){
    ITER(_c) _it=_c.begin();
    if(_p){cout<<_n<<" = ["<<endl;for(;_it!=_c.end();++_it)cout<<"    "<<*_it<<endl;cout<<"]"<<endl; }
    else{cout<<_n<<" = [ "<<*_it++;for(;_it!=_c.end();++_it)cout<<", "<<*_it;cout<<" ]"<<endl; }
}
#define pf printf
#define pr(n) do{cout<<#n" = "<<(n)<<endl;}while(0)
#define prfe(n) _prfe(#n, n)
#define prfep(n) _prfe(#n, n, true)
#define dbgchk(n) do{if(n)throw;}while(0)
#else
#define pf(...) /* */
#define pr(...) /* */
#define prfe(...) /* */
#define prfep(...) /* */
#define dbgchk(...) /* */
#endif

const int dir[][2] = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};

int dfs(int n, vector<vector<int> > &v, vector<vector<int> > &f){
    pf("---- %d ----\n", n);
    REP(y,10) pr(join(v[y]));

    if(n < 10){
        int y = n / 10, x = n % 10, ret;

        ret = dfs(n+1,v,f);
        if(ret > 0) return 1;
        REP(j,5){
            int mx = x + dir[j][0], my = y + dir[j][1];
            if(mx < 0 || my < 0 || mx >= 10 || my >= 10) continue;
            v[my][mx] ^= 1;
        }
        f[y][x] = 1;

        ret = dfs(n+1,v,f);
        if(ret > 0) return 1;
        REP(j,5){
            int mx = x + dir[j][0], my = y + dir[j][1];
            if(mx < 0 || my < 0 || mx >= 10 || my >= 10) continue;
            v[my][mx] ^= 1;
        }
        f[y][x] = 0;
        return 0;
    }

    vector<vector<int> > v0 = v, f0 = f;
    FROMTO(i,n,100){
        int y = i / 10, x = i % 10;
        if(v0[y-1][x] == 0) continue;
        REP(j,5){
            int mx = x + dir[j][0], my = y + dir[j][1];
            if(mx < 0 || my < 0 || mx >= 10 || my >= 10) continue;
            v0[my][mx] ^= 1;
        }
        f0[y][x] = 1;
    }

    pf("---- check ----\n");
    REP(y,10){
        pr(join(v0[y]));
        REP(x,10){
            if(v0[y][x]) return 0;
        }
    }
    f = f0;
    return 1;
}

vector<vector<int> > fm;

void solve(vector<vector<int> > &v){
    vector<vector<int> > f(10, vector<int>(10));
    if(!dfs(0,v,f)) throw;
    REP(y,10) cout << join(f[y]) << endl;
    fm = f;
}

int main(){
    int n;
    cin >> n;
    REP(i,n){
        vector<vector<int> > v(10, vector<int>(10));
        REP(y,10) REP(x,10)
            cin >> v[y][x];
        solve(v);
    }
    return 0;
}
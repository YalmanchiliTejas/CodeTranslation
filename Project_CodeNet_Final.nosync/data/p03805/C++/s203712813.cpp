#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS
#include "MyLib.h"
#else
#define main_C main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define MGN 8
#define LINF (LONG_MAX/2)
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<vi> vvi;
typedef vector<ll> vl; typedef vector<vl> vvl;
typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<bool> vb; typedef vector<vb> vvb;
template <typename T>
using keyVal = pair<string, T>;
template<typename T>
bool val_greater(const keyVal<T>& left, const keyVal<T>& right) {
    return left.second > right.second;
}
vs split(string str, char sep) {
    vs v; stringstream ss(str); string t;
    while (getline(ss, t, sep)) v.push_back(t);
    return v;}
vs re_search_g(string s, regex re) {
    vs ret; smatch mc; auto it = s.cbegin();
    while (regex_search(it, s.cend(), mc, re)) {
        ret.push_back(mc[0]);
        it += mc.position(0) + mc.length();}
    return ret;}
#endif

void init_global_C() {}

int N, M;
vvi e;
vb visited;
int cnt = 0;

void dfs(int t, int x) {
    if (visited[x]) return;
    visited[x] = true;

    if (t >= N-1) {
        bool ok = true;
        FOR(i,1,N+1) {
            if (!visited[i]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
        visited[x] = false;
        return;
    }

    for(int i : e[x]){
        dfs(t + 1, i);
    }

    visited[x] = false;
}

int main_C() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vi a(M), b(M); REP(i,M) cin >> a[i] >> b[i];
    
    e = vvi(N + 1);

    REP(i,M) {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }

    visited = vb(N+1, false);
    cnt = 0;

    dfs(0, 1);

    int ans = cnt;
    cout << ans << endl;  

    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 400005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 +c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
    	out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
pii p[MAXN];
multiset<int> sb,sr;
void Solve() {
    read(N);
    int x,y;
    for(int i = 1 ; i <= N ; ++i) {
        read(x);read(y);
        if(x > y) swap(x,y);
        p[i] = mp(x,y);
        sb.insert(x);sr.insert(y);
    }
    sort(p + 1,p + N + 1);
    int64 ans = 1e18;
    for(int i = 1 ; i <= N ; ++i) {
        int a = *(--sr.end()) - *sr.begin();
        int b = *(--sb.end()) - *sb.begin();
        ans = min(ans,1LL * a * b);
        sr.erase(sr.find(p[i].se));
        sr.insert(p[i].fi);
        sb.erase(sb.find(p[i].fi));
        sb.insert(p[i].se);
    }
    out(ans);enter;
}
int main() {
    Solve();
}
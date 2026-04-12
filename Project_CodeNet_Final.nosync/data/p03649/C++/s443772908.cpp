#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 200005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 + c - '0';
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
int64 a[55],ans;
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(a[i]);
    while(1) {
	int t = 1;
	for(int i = 2 ; i <= N ; ++i) {
	    if(a[i] > a[t]) t = i;
	}
	if(a[t] < N) break;
	int64 k = (a[t] - (N - 1) - 1) / N + 1;
	a[t] -= k * N;
	ans += k;
	for(int i = 1 ; i <= N ; ++i) {
	    if(i != t) a[i] += k;
	}
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

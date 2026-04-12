#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 200005
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
int a[MAXN];
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(a[i]);
    if(N & 1) {
	for(int i = N ; i >= 1 ; i -= 2) {out(a[i]);space;}
	for(int i = i = 2 ; i <= N ; i += 2) {out(a[i]);space;}
	enter;
    }
    else {
	for(int i = N ; i >= 1 ; i -= 2) {out(a[i]);space;}
	for(int i = 1 ; i <= N ; i += 2) {out(a[i]);space;}
	enter;
    }

}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

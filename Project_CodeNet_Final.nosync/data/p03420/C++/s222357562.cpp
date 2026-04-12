#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 100005
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
int N,K;
int64 ans;
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    read(N);read(K);
    for(int i = 1 ; i <= N ; ++i) {
	if(i <= K) continue;
	ans += i - K;if(K == 0) --ans;
	int t = N / i - 1;
	ans += t * (i - K);
	t = N / i * i + K;
	if(t <= N) ans += N - t + 1;
    }
    out(ans);enter;
    return 0;
}

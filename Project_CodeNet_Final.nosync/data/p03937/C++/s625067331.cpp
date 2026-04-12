#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
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
int H,W,cnt[30];
char s[15][15];
bool vis[15][15];
void Solve() {
    read(H);read(W);
    for(int i = 1 ; i <= H ; ++i) {
        scanf("%s",s[i] + 1);
    }
    for(int i = 1 ; i <= H ; ++i) {
        for(int j = 1 ; j <= W ; ++j) {
            if(s[i][j] == '#') {
                ++cnt[i + j];
                if(cnt[i + j] >= 2) {puts("Impossible");return;}
            }
        }
    }
    puts("Possible");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

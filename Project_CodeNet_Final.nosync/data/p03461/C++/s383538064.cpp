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
int A,B;
int d[15][15];
int f[105][105],tot,gx[105],gy[105],S,T;
pii p[305 * 305];
int val[305 * 305],cnt;
int check(int x,int y) {
    int res = 1000000;
    for(int i = 0 ; i <= 100 ; ++i) {
	for(int j = 0 ; j <= 100 ; ++j) {
	    res = min(res,f[i][j] + i * x + j * y);
	}
    }
    return res;
}
void Solve() {
    read(A);read(B);
    for(int i = 1 ; i <= A ; ++i) {
	for(int j = 1 ; j <= B ; ++j) {
	    read(d[i][j]);
	}
    }
    for(int i = 0 ; i <= 100 ; ++i) {
	for(int j = 0 ; j <= 100 ; ++j) {
	    for(int k = 1 ; k <= A ; ++k) {
		for(int h = 1 ; h <= B ; ++h) {
		    f[i][j] = max(f[i][j],d[k][h] - k * i - h * j);
		}
	    }
	} 
    }
    for(int i = 1 ; i <= A ; ++i) {
	for(int j = 1 ; j <= B ; ++j) {
	    if(check(i,j) != d[i][j]) {
		puts("Impossible");
		return;
	    }
	}
    }
    puts("Possible");
    S = ++tot;
    gx[0] = S;
    for(int i = 1 ; i <= 100 ; ++i) {
	gx[i] = ++tot;
	p[++cnt] = mp(gx[i - 1],gx[i]);
	val[cnt] = -2;
    }
    T = ++tot;
    gy[0] = T;
    for(int i = 1 ; i <= 100 ; ++i) {
	gy[i] = ++tot;
	p[++cnt] = mp(gy[i],gy[i - 1]);
	val[cnt] = -1;
    }
    for(int i = 0 ; i <= 100 ; ++i) {
	for(int j = 0 ; j <= 100 ; ++j) {
	    p[++cnt] = mp(gx[i],gy[j]);
	    val[cnt] = f[i][j];
	}
    }
    out(tot);space;out(cnt);enter;
    for(int i = 1 ; i <= cnt ; ++i) {
	out(p[i].fi);space;out(p[i].se);space;
	if(val[i] < 0) {
	    if(val[i] == -2) {puts("X");}
	    else puts("Y");
	}
	else {out(val[i]);enter;}
    }
    out(S);space;out(T);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

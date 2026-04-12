/*
Arthor : Ender_zzm
E-mail zzm_ender_wiggin@outlook.com
Blog ender-zzm.enbar.cn
*/
#include <bits/stdc++.h>
using namespace std;

inline int Isdigit(char c) {
	if (c < '0' || c > '9') return 0;
	return 1;
}
inline int readint(){
    register int x = 0, flag = 1;
    register char ch;
    while (!Isdigit(ch = getchar())) if (ch == '-') flag = -1;
    while (x = x * 10 + (ch & 15), Isdigit(ch = getchar()));
	return x * flag;
}

inline long long readlong() {
	register long long x = 0, flag = 1;
	register char ch;
	while (!Isdigit(ch = getchar())) if (ch == '-') flag = -1;
    while (x = x * 10 + (ch & 15), Isdigit(ch = getchar()));
	return x * flag;
}
template <class T>
inline void write(T x){
    if (x < 0)
        putchar('-'), x = -x;
    if(x >= 10) write(x / 10); 
    putchar(x % 10 + '0');
}

template<class T> inline bool Chkmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<class T> inline bool Chkmin(T& x, const T& y) { return x > y ? x = y, true : false; }

#define For(i, x, y) for (int i = (x); i <= (y); i++) 
#define Rep(i, x, y) for (int i = (x); i >= (y); i--) 
#define ri readint
#define rl readlong

int main() {
	int x;
	x = ri();
	if (x >= 30) puts("Yes");
	else puts("No");
}

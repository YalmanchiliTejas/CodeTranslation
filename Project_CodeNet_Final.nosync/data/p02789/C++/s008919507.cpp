#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
    return x;
}
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
inline void write(int x){if (x > 9) write(x/10); putchar(x%10+'0'); }
int n,m;
int main(){
	n = read(),m = read();
	if (n==m) puts("Yes"); else puts("No");
    return 0;
}
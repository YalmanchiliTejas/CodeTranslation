#include<bits/stdc++.h>
//#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++ i)

inline int read() 
{
	char cc = getchar(); int cn(0), flus(1);
	while(cc < '0' || cc > '9') {if(cc == '-') flus = -flus; cc = getchar();}
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - 48; cc = getchar();}
	return cn * flus;
}

const int MAXN = 1e5 + 10, INF = 2147483647;
const int Mod = 998244353, G = 3;

signed main()
{
	int n = read();
	if(n >= 30) puts("Yes");
	else puts("No");
	return 0;
}
#include<bits/stdc++.h>
#define N 40010
#define int long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define rep(i, l, r) for(register int i = l; i <= r; ++ i)
using namespace std;
inline int read()
{
	register char cc = getchar();register int cn(0), flus(1);
	while(cc > '9' || cc < '0') {if(cc == '-') flus = -flus; cc = getchar();}
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - '0'; cc = getchar();}
	return cn * flus; 
}
signed main()
{
	int n = read(), m = read();
	if(n == m) printf("Yes\n");
	else printf("No\n");
	return 0;
}
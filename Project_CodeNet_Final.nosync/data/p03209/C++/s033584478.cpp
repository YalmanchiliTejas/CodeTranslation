#include <bits/stdc++.h>
#define int long long
#define maxn 100
using namespace std;
int n, m;
template<class T>
inline void read(T &a){
	int s = 0, w = 1; char c;
	while(c < '0' || c > '9') {if(c == '-') w = -1; c = getchar();}
	while(c >= '0' && c <= '9'){s = (s << 1) + (s << 3) + (c ^ 48); c = getchar();}
	a = s*w;
}
int a[maxn], b[maxn];
int dfs(int n, int x){
if(x == 0 || (x == 1) && (n != 0)) return 0;
	if(x == b[n]) return a[n];
    if(n == 0) return 1;
	if(x <= 1) return 0;
	if(x >= b[n-1]*2 + 2) return a[n-1] * 2 + 1;
	else{
		if(x >= b[n-1] + 2) return a[n-1] + 1 + dfs(n - 1, x - b[n-1] - 2);
			else{
				 return dfs(n - 1, x - 1);
			}
		}
}
signed main(){
	read(n); read(m);
	a[0] = b[0] = 1;
	for (int i = 1; i <= n; i++){
		a[i] = a[i-1] * 2 + 1;
		b[i] = b[i-1] * 2 + 3;
	}
	printf("%lld", dfs(n, m));
	return 0;
}

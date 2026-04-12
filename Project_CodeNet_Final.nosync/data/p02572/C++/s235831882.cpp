#include<bits/stdc++.h>
#define inf 0x7fffffff
#define maxn 100005
#define maxm 100005
#define eps 1e-6
typedef long long ll;
using namespace std; 
const ll mod = 1e9 + 7;
inline int read(){
	int x = 0, f = 1;char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
	return x * f;
}

int n ;
ll x, sum ,ans;
int main(){
	int i, j;
	n = read();
	for(i = 1;i <=n;i++){
		x = read();
		ans = (ans +sum *x%mod)%mod;
		sum=(sum + x)%mod;
	}
	cout<<ans;
}
//
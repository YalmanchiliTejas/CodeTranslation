#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 3005;
LL P;

LL kpw(LL x,LL y,LL M){
	LL ans = 1,tmp = x;
	while(y){
		if(y & 1) ans = (ans * tmp) % M;
		tmp = (tmp * tmp) % M;
		y >>= 1;
	}
	return ans;
}

LL c[N][N],s[N][N];
void init_cs(){
	for(LL i = 0;i <= 3001;i ++) c[i][0] = c[i][i] = 1;
	s[0][0] = 1;
	for(LL i = 1;i <= 3001;i ++){
		for(LL j = 1;j <= 3001;j ++){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
			s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % P;
		}
	}
}

int main(){
	LL n,tmp,ans = 0;
	cin >> n >> P; init_cs();
	for(LL i = 0;i <= n;i ++){
		tmp = 0;
		for(LL j = 1;j <= i + 1;j ++) tmp = (tmp + s[i + 1][j] * kpw(2LL,(j - 1) * (n - i),P) % P) % P;
		tmp = ((kpw(2LL,kpw(2LL,n - i,P - 1),P) * c[n][i]) % P * tmp) % P;
		if(i & 1) ans = (ans - tmp + P) % P;
		else ans = (ans + tmp) % P;
	}
	cout << ans << '\n';
	return 0;
}
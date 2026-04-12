#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const int N = 3001;
const int MAXN = N + 5;

int n,M,ans;
int c[MAXN][MAXN],s[MAXN][MAXN];

namespace ModOperation{
	int mul(int x,int y){
		return 1ll * x * y % M;
	}
	
	int add(int x,int y){
		x += y;
		if(x >= M)
			x -= M;
		return x;
	}
	
	int sub(int x,int y){
		x -= y;
		if(x < 0)
			x += M;
		return x;
	}
}

using namespace ModOperation;

int power(int x,int y,int MOD = M){
	int res = 1;
	while(y){
		if(y & 1)
			res = 1ll * res * x % MOD;
		x = 1ll * x * x % MOD;
		y >>= 1;
	}
	return res;
}

void Init(){
	c[0][0] = s[0][0] = 1;
	for(int i = 1;i <= N;i++){
		c[i][0] = 1;
		for(int j = 1;j <= i;j++){
			c[i][j] = add(c[i - 1][j],c[i - 1][j - 1]);
			s[i][j] = add(s[i - 1][j - 1],mul(j,s[i - 1][j]));
		}
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&M);
	Init();
	for(int i = 0;i <= n;i++){
		int pow2 = power(2,n - i);
		int res1 = mul(c[n][i],power(2,power(2,n - i,M - 1)));
		int tmp = 1,res2 = 0;
		for(int j = 0;j <= i;j++){
			res2 = add(res2,mul(s[i + 1][j + 1],tmp));
			tmp = mul(tmp,pow2);
		}
		if(i & 1)
			ans = sub(ans,mul(res1,res2));
		else
			ans = add(ans,mul(res1,res2));
	}
	printf("%d\n",ans);
	return 0;
}


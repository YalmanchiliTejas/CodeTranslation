#include<cstdio>
int c[3003][3003];
int n,mod,p2[3003],pp2[3003];
int add(int x,int y){
	return (int)(((long long int)(x)+y)%mod);
}
int sub(int x,int y){
	return add(x, mod-y);
}
int mul(int x,int y,int mod){
	return (int)((long long int)x*y%mod);
}
int mul(int x,int y){
	return mul(x,y,mod);
}
int s2[3003][3003];
int calc(int x){
	int w = p2[n-x], res = 0;
	for(int k=x; k>=0; k--){
		res = add(mul(res, p2[n-x]), s2[x][k]);
	}
	res = mul(res, pp2[n-x]);
	return res;
}
int main(){
	scanf("%d%d",&n,&mod);
	p2[0] = 1; pp2[0] = 2;
	for(int i=1; i<=n; i++){
		p2[i] = add(p2[i-1], p2[i-1]);
		pp2[i] = mul(pp2[i-1], pp2[i-1]);
	}
	for(int i=0; i<=n; i++)
		for(int j=0; j<=i; j++){
			c[i][j] = j==0||j==i?1:add(c[i-1][j],c[i-1][j-1]);
			s2[i][j] = j==0||j==i?1:add(s2[i-1][j-1], mul(s2[i-1][j],j+1));
		}
	int res = 0;
	for(int i=0; i<=n; i++){
		int tmp = mul(c[n][i], calc(i));
		if(i%2)
			res = sub(res, tmp);
		else
			res = add(res, tmp);
	}
	printf("%d\n",res);
	return 0;
}
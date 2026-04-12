#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
const int C=10001, D=101, M=1000000007;

char k[C];
ll dp[C][D], wynn;

int sget(char tab[]){
	for (int z=0;;z++){
		tab[z]=getchar();
		if (tab[z]<=32)	return z;
	}
}

int main(){
	int i, j, ij, c, m, x, sum=0;
	dp[0][0]=1;
	x=sget(k);
	scanf ("%d", &m);
	
	for (i=1;i<C;i++){
		for (j=0;j<m;j++){
			for (ij=0;ij<10;ij++){
				c=(j-ij)%m;
				if (c<0)	c+=m;
				dp[i][j]=(dp[i][j]+dp[i-1][c])%M;
			}
		}
	}
	
	wynn=M-1;	
	for (i=0;i<x;i++){
		for (j=0;j<k[i]-48;j++){
			c=(m-sum-j)%m;
			if (c<0)	c+=m;
			wynn=(wynn+dp[x-i-1][c])%M;
		}
		sum=sum+k[i]-48;
	}
	if (sum%m==0)	wynn++;
	
	printf ("%lld", wynn);
	
	
return 0;}
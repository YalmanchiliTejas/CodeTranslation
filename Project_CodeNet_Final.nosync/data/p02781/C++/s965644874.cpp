#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fs first
#define sc second
#define P pair<int, int>
#define mk_p make_pair
int a[111], len, K;
LL f[111][5][2];
char s[111];
int main(){
	LL ans = 0;
	cin>>s + 1;
	cin>>K;
	len = strlen(s + 1);
	for(int i = 1;i <= len; i++)a[i] = s[i] - '0';
	f[0][0][1] = 1;
	for(int i = 0;i < len; i++){
		for(int j = 0;j <= K; j++){
			if(!a[i+1])f[i+1][j][1] += f[i][j][1];
			else f[i+1][j+1][1] += f[i][j][1], f[i+1][j+1][0] += f[i][j][1] * (a[i+1] - 1), f[i+1][j][0] += f[i][j][1];
			f[i+1][j][0] += f[i][j][0];
			f[i+1][j+1][0] += f[i][j][0] * 9;
//			printf("i=%d j=%d f0=%lld f1=%lld\n", i, j, f[i][j][0], f[i][j][1]);
		}
	}
	cout<<f[len][K][1] + f[len][K][0]<<endl;
	return 0;
}
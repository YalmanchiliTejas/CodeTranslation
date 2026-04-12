#include<bits/stdc++.h>
using namespace std;

#define i64 long long int
#define ran 202202

int n;
int a[ran];
i64 f[ran][3];

void upd(i64 &a, i64 b) {
	if(a<b) a = b;
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	
	int emp = 1+n%2;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=emp;j++)
			f[i][j] = -1e18;
	f[0][0] = 0;
	f[1][0] = a[1];
	f[2][1] = a[2];
	f[3][0] = f[1][0] + a[3];
	f[3][2] = a[3];
	for(int i=4;i<=n;i++) {
		for(int j=0;j<=emp;j++) {
			f[i][j] = -1e18;
			if(f[i-2][j]>-1e18)
				upd(f[i][j], f[i-2][j] + a[i]);
			if(j>=1 && i>3 && f[i-3][j-1]>-1e18)
				upd(f[i][j], f[i-3][j-1] + a[i]);
			if(emp>1 && j==2 && i>4 && f[i-4][j-2]>-1e18)
				upd(f[i][j], f[i-4][j-1] + a[i]);
			
			//printf("%d %d %lld\n", i, j, f[i][j]);
		}
	}

	i64 ans = -1e18;
	for(int i=0;i<=emp;i++)
		ans = max(ans, f[n-i][emp-i]);
	printf("%lld\n", ans);
	
	return 0;
}
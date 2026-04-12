#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
const int C=3001;

int n;
ll a[C], dp[C][C];

int main(){
	int i, j;
	scanf ("%d", &n);
	for (i=0;i<n;i++)	scanf ("%lld", &a[i]);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (j+i>=n)	break;
			if (i==0)	dp[j][j]=a[j];
			else dp[j][j+i]=max(a[i+j]-dp[j][i+j-1], a[j]-dp[j+1][i+j]);
		}
	}
	printf ("%lld\n", dp[0][n-1]);
	
return 0;}
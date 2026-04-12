#include <iostream>
using namespace std;

int main() {
	int n,a[3000];
	long long int dp[3000][3000];
	scanf("%d",&n);
	for(int i=0;i<n;i+=1){
	    scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i+=1){
	    for(int j=0;j+i<n;j+=1){
	        if(i==0){
	            dp[j][i+j]=a[i];
	            continue;
	        }
	        if(i==1){
	            dp[j][j+i]=abs(a[j+i]-a[j]);
	            continue;
	        }
	        dp[j][i+j]=max(a[i+j]-dp[j][i+j-1],a[j]-dp[j+1][i+j]);
	    }
	}
	printf("%lld",dp[0][n-1]);
	return 0;
}

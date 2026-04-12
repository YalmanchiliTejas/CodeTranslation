#include<bits/stdc++.h>
#define randome_generate srand(std::chrono::high_resolution_clock::now().time_since_epoch().count())
using namespace std;
long long dp[3100][3100];
int n;
long long a[3100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i];
	for(int q=1;q<=n-1;q++){
		for(int i=1;i<=n-q;i++){
			int j=i+q;
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}

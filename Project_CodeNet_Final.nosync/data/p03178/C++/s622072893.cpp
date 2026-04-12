#include<bits/stdc++.h>
#define MOD 1000000007
#define randome_generate srand(std::chrono::high_resolution_clock::now().time_since_epoch().count())
using namespace std;
string k;
int d;
int dp[10010][101];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>k>>d;
	int l=k.size();
	int he=0;
	for(int i=1;i<=l;i++){
		for(int j=0;j<k[i-1]-'0';j++)
			dp[i][(j+he)%d]++;
		he+=(k[i-1]-'0');
	}
	dp[l][he%d]++;
	//dp
	for(int i=1;i<=l;i++){
		for(int j=0;j<d;j++){
			for(int cur=0;cur<=9;cur++){
				dp[i][j]=(dp[i][j]+dp[i-1][((j-cur)%d+d)%d])%MOD;
			}
		}
	}
	cout<<(dp[l][0]-1+MOD)%MOD<<endl;
	return 0;
}

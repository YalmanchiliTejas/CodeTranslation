#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	string N;
	cin >> N;
	int s=N.size();
	int K;
	cin >> K;
	int dp0[110][5]={0}, dp1[110][5]={0};
	dp0[0][0]=1;
	rep(i,s){
		int n=N[i]-'0';
		rep(j,4){
			if(n!=0){
				dp0[i+1][j+1]+=dp0[i][j];
				dp1[i+1][j]+=dp0[i][j]+dp1[i][j];
				dp1[i+1][j+1]+=dp0[i][j]*(n-1)+dp1[i][j]*9;
			}
			else{
				dp0[i+1][j]+=dp0[i][j];
				dp1[i+1][j]+=dp1[i][j];
				dp1[i+1][j+1]+=dp1[i][j]*9;
			}
		}
	}
	cout << dp0[s][K]+dp1[s][K] << endl;

	return 0;
}
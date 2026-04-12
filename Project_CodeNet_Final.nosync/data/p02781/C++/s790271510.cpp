#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
using namespace std;


const long long int mod=1000000007;
const long long int INF=99999999999999999;



string N;
long long int K,A[200005],Sum[200005]={},res=0,dp[105][4]={},dp2[105][4]={};

int main() {
	cout << fixed << setprecision(18);
	cin>>N>>K;
	dp[1][1]=1;
	dp2[1][1]=N[0]-'1';
	for(int i=1;i<N.length();i++){
		if(N[i]=='0'){
			//0
			dp[i+1][3]+=dp[i][3];
			dp[i+1][2]+=dp[i][2];
			dp[i+1][1]+=dp[i][1];

			//not0
			dp2[i+1][3]+=9*dp2[i][2];
			dp2[i+1][2]+=9*dp2[i][1];

			//0
			dp2[i+1][3]+=dp2[i][3];
			dp2[i+1][2]+=dp2[i][2];
			dp2[i+1][1]+=dp2[i][1];

			dp2[i+1][1]+=9LL;
			
		}else{
			//not 0
			dp[i+1][3]+=dp[i][2];
			dp[i+1][2]+=dp[i][1];
			//not 0
			dp2[i+1][3]+=(N[i]-'1')*dp[i][2];
			dp2[i+1][2]+=(N[i]-'1')*dp[i][1];
			//not0
			dp2[i+1][3]+=9*dp2[i][2];
			dp2[i+1][2]+=9*dp2[i][1];
			//0
			dp2[i+1][3]+=dp2[i][3]+dp[i][3];
			dp2[i+1][2]+=dp2[i][2]+dp[i][2];
			dp2[i+1][1]+=dp2[i][1]+dp[i][1];

			
			dp2[i+1][1]+=9LL;
		}
	}
	cout<<dp2[N.length()][K]+dp[N.length()][K];
} 
#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
//const int MAX=;


//dp[i][j]はi個残りj番目からの状態での最善
lli dp[3002][3002];

int main(){
	int N;
	cin>>N;
	lli a[3002];
	rep1(i,N)cin>>a[i];
	
	rep1(j,N)dp[1][j]=a[j];
	for(int i=2;i<=N;i++)rep1(j,N){
		if(i+j-1>N)break;
		dp[i][j]=max(a[i+j-1]-dp[i-1][j],a[j]-dp[i-1][j+1]);
	}
	cout<<dp[N][1];
}
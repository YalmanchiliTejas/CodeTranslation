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
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=1e5+5;
const int MOD=1e9+7;


//dp[i][j]/Kの上からi桁目まで以下の数で、modDでjのものの個数
int dp[MAX][100];

int main(){
	string K;
	cin>>K;
	int D;
	cin>>D;
	int N=sz(K);
	vector<int> v={0};
	rep(i,N){
		int x=K[i]-'0';
		v.push_back(x);
	}
	int s[MAX];
	s[0]=v[0];
	rep1(i,N)s[i]=s[i-1]+v[i];
	
	dp[0][0]=1;
	rep1(i,N){
		rep(j,D)rep(k,10)dp[i][j]=(dp[i][j]+dp[i-1][(j+10*D-k)%D])%MOD;
		for(int k=s[i]+1;k<=s[i-1]+9;k++)dp[i][k%D]=(dp[i][k%D]+MOD-1)%MOD;
	}
 	cout<<(dp[N][0]+MOD-1)%MOD<<endl;
}

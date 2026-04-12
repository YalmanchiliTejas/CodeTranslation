#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

string k;
int d;
ll dp[10010][110][2];

void input(){
	cin>>k>>d;
	return;
}

void solve(){
	dp[0][0][1]=1;
	for(int i=0;i<k.size();i++){
		for(int j=0;j<d;j++){
			for(int l=0;l<=9;l++){
				if(l<(k[i]-'0')){
					dp[i+1][(j+l)%d][0]+=dp[i][j][0]+dp[i][j][1];
					dp[i+1][(j+l)%d][0]%=MOD;
				}
				else if(l==(k[i]-'0')){
					dp[i+1][(j+l)%d][0]+=dp[i][j][0];
					dp[i+1][(j+l)%d][1]+=dp[i][j][1];
					dp[i+1][(j+l)%d][0]%=MOD;
					dp[i+1][(j+l)%d][1]%=MOD;
				}
				else {
					dp[i+1][(j+l)%d][0]+=dp[i][j][0];
					dp[i+1][(j+l)%d][0]%=MOD;
				}
			}
		}
	}
	cout<<(dp[k.size()][0][0]+dp[k.size()][0][1]-1+MOD)%MOD<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}
//*********Abhay is awesome *************\\

#include<bits/stdc++.h>


#define pb push_back
#define popb pop_back
#define mt make_tuple 
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define piii pair<int,pii>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repc(i,a,n) for(int i=a;i<n;++i)
#define  repd(i,a,n) for(int i=a;i>n;--i)

using namespace std;
using ll = long long;
const ll N = 3*1e5 +5 ;
const ll mod = 998244353 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;

//typedef vetor<int> vi;
ll dp[3010][3010][3];

void solve(){
	int n,s;
	cin>>n>>s;
	int a[n];
	dp[0][0][0]=1;
	rep(i,n)cin>>a[i];
	rep(i,n){
		rep(j,s+1){
			(dp[i+1][j][0]+=dp[i][j][0] )%= mod;
			(dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1]) %= mod;
			(dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=mod;
			if(j+a[i]<=s){
				(dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1])%= mod;
				(dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1]) %= mod;
			}
		}
	}
	cout<<dp[n][s][2];
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//#ifndef ONLINE_JUDGE
    // for getting input from input.txt
  //  freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //freopen("output1.txt", "w", stdout);
	//#endif
	//cout<<"HEy";
	solve(); 
	return  0;
}



/////////////

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;

// [ith_digit][bound][no_of_non_zero_digits]
// [100][2][100] * 10
const int maxn = 100+5;
int dp[maxn][2][maxn],n,k;
string s;
int solve(int i,int bnd,int cnt){
	if( i == n )return cnt == k;
	int &ans = dp[i][bnd][cnt];
	if( ans != -1 )return ans;
	ans = 0;
	if(bnd){
		for(int d=0;d<s[i]-'0';d++){
			ans+=solve(i+1,0,cnt+(d!=0));
		}
		ans+=solve(i+1,1,cnt+(s[i]-'0'!=0));
	}else{
		for(int d=0;d<10;d++){
			ans+=solve(i+1,0,cnt+(d!=0));
		}
	}
	return ans;
}
int32_t main(){
	IOS
	memset(dp,-1,sizeof(dp));
	cin>>s>>k;n=s.length();
	cout<<solve(0,1,0);
	
 }
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
#define dbg if(debug)
using namespace std;
const bool debug = 0;

string s;
int d;
int dp[10005][100][2];

int solve(int i,int r,bool lt){
	if(i==s.length())
		return (r==0);
	int &ans = dp[i][r][lt];
	if(ans!=-1)
		return ans;
	ans = 0;
	if(lt){
		int x = 0;
		for(;x<s[i]-'0';++x){
			ans = (ans + solve(i+1,(r+x)%d,0))%mod;
		}
		ans = (ans + solve(i+1,(r+x)%d,1))%mod;
	}
	else{
		int x = 0;
		for(;x<10;++x){
			ans = (ans + solve(i+1,(r+x)%d,0))%mod;
		}
	}
	// cout<<i<<" : "<<lt<<" ::"<<ans<<'\n';
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>s>>d;
	memset(dp,-1,sizeof dp);

	cout<<(mod+solve(0,0,1)-1)%mod;

	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}
/*input
30
4
*/

#include <bits/stdc++.h>
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define int long long int
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printsf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
const int MOD = 1000000007;

string K; int D; int n;
int dp[10009][2][200];
int solve(int pos,bool prev,int sum){
	if(pos==n){
		if(sum%D==0) return 1;
		else return 0;
	}
	if(dp[pos][prev][sum]!=-1) return dp[pos][prev][sum]; 
	
	int till = prev?(K[pos]-'0'):9;
	int ans = 0;
	for(int i=0;i<=till;i++){
		ans = (ans%MOD + solve(pos+1,prev and i==till,(sum%D+i%D)%D)%MOD)%MOD;
	}
	return dp[pos][prev][sum]=ans;
}
signed main(){
	memset(dp,-1,sizeof dp);
	cin>>K>>D;
	n = K.size();
	int ans = solve(0,1,0); cout<<(ans-1+MOD)%MOD;
}


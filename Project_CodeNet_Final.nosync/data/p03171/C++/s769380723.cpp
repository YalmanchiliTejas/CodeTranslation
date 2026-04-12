#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for( int i = a; i < b ; i++ ) 
#define af(i,a,b) for( int i = a; i >= b ; i--)
#define rep(i,a,b,k) for(int i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( int i = a; i >= b ; i-= k)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PI 3.14159265358979323846

typedef long double ld;
typedef long long int ll;
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii 	;
ll inf=1e9;
ll num[100010];
ll dp[3010][3010];
ll solve(int i,int j,int p){
	if(dp[i][j]!=-inf) return dp[i][j];
	if(i==j){
		if(p==0) return num[i];
		else return -num[i];
	}
	if(p==0){
		ll a= max(solve(i+1,j,1)+num[i],solve(i,j-1,1)+num[j]);
		dp[i][j]=a;
		return a;		
	}
	else{
		ll b=min(solve(i+1,j,0)-num[i],solve(i,j-1,0)-num[j]);
		dp[i][j]=b;
		return b;
	}
}
int main(){
	fastio;
	int n,k;
	cin>>n;
	f(i,0,n) cin>>num[i];
	f(i,0,n) f(j,0,n) dp[i][j]=-inf;
	cout<<solve(0,n-1,0);
}
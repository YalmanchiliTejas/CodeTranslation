/* Fairy dandy tickling the fancy of his lady friend */

#include <iostream>

#include <vector>

#include <algorithm>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

#define rep(i,a,b) for(int i=int(a); i<int(b); i++)

#define rip(i,a,b) for(int i=(int)a; i>=(int)b; i--)

#define pb push_back

#define mp make_pair

#define fst first

#define snd second

#define sz(x) int(x.size())

#define all(v) (v).begin(), (v).end()

#define trace(x) cerr << #x << ": " << x <<endl;

using namespace std;
const int MOD = 1e9+7;

typedef long long int lli;

typedef pair<lli, lli> ii;

typedef vector<int> vi;

typedef vector<ii> vii;


lli dp[10005][105];
lli dpf[10005][105];
lli ans;


int main(){

    fastio;

	string k;
	lli d;
	cin>>k>>d;
	reverse(all(k));
	lli n=sz(k);
	rep(i, 1, 10){
		if(i<=k[0]-'0')
			dpf[0][i%d]++;
		dp[0][i%d]++;
	}
	if(n==1){
		cout<<dpf[0][0]<<endl;
		return 0;
	}
	ans+=dp[0][0];
	dp[0][0]++;
	dpf[0][0]++;
	rep(i, 1, n-1){
		rep(j, 1, 10){
			rep(l, 0, d){
				lli cur= (j+l)%d;
				if(j<k[i]-'0')
					dpf[i][cur]=(dpf[i][cur]+dp[i-1][l])%MOD;
				dp[i][cur]=(dp[i][cur]+dp[i-1][l])%MOD;
			}
		}
		ans = (ans+dp[i][0])%MOD;
		rep(j, 0, d){
			dpf[i][(k[i]-'0'+j)%d]=(dpf[i][(k[i]-'0'+j)%d]+dpf[i-1][j])%MOD;
			if(k[i]>'0') dpf[i][j]=(dpf[i][j]+dp[i-1][j])%MOD;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
		}
	}
	rep(i, 1, k[n-1]-'0') rep(j, 0, d)
			dp[n-1][(j+i)%d]=(dp[n-1][(j+i)%d]+dp[n-2][j])%MOD;
	ans = (ans+dp[n-1][0])%MOD;
	rep(i, 0, d){
		lli cur = ((k[n-1]-'0')+i)%d;
		dpf[n-1][cur]=(dpf[n-1][cur]+dpf[n-2][i])%MOD;
	}
	ans=(ans+dpf[n-1][0])%MOD;
	cout<<ans<<endl;

    return 0;

}
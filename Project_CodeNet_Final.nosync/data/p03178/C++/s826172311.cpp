#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1e9+7;
const ll ARR_MAX = 1e5+1;
const ll VAL_MAX = 103;
const ll INF=1e14;


ll dp[VAL_MAX][2],previ[VAL_MAX][2];
//dp[i][j] = number of numbers so far with sum of digits having modulo i,with j being a bool representing if digits chosen are identical to k.
//1 represents identical digits so far.

void add_mod(ll &x,ll y){
	x+=y;
	if(x>=MOD){
		x-=MOD;
	}
}

void solve(){
    string k;cin>>k;
    int d;cin>>d;
    int n=k.size();
    dp[0][1]=1;
    // for(int x=0;x<d;x++){
   	// 	cout<<-1<<" . "<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<nl;
   	// }

    for(int i=0;i<n;i++){
    	int dig=k[i]-'0';
    	for(int x=0;x<d;x++){
    		previ[x][0]=dp[x][0];
    		previ[x][1]=dp[x][1];
    		dp[x][0]=0;
    		dp[x][1]=0;
    	}
    	for(int j=0;j<10;j++){
    		for(int x=0;x<d;x++){
    			if(j<dig){
    				add_mod(dp[(x+j)%d][0],previ[x][1]);
    				add_mod(dp[(x+j)%d][0],previ[x][0]);
    			}
    			else if(j==dig){
    				add_mod(dp[(x+j)%d][0],previ[x][0]);
    				add_mod(dp[(x+j)%d][1],previ[x][1]);    				
    			}
    			else{
    				add_mod(dp[(x+j)%d][0],previ[x][0]);    				
    			}
    		}
    	}
    	// for(int x=0;x<d;x++){
    	// 	cout<<i<<" . "<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<nl;
    	// }
    }
    cout<<(dp[0][0]+dp[0][1]+MOD-1)%MOD<<nl;
}

int main(){
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
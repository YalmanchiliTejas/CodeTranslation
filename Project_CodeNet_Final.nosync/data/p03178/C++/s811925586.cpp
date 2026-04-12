#include<bits/stdc++.h>
#define pb          push_back
#define endl        '\n'
#define pll         pair<int,int>
#define vll          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define int	    int64_t
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
int n,i,j,k,l,sum=0,flag=0,t,ans=0;
int dp[10001][101][2];
string s;
int f(int pos, int rem , int bada){
	//cout<<pos<<" "<<rem<<" "<<bada<<endl;
	if(pos==n)
		return (rem == 0);
	if(dp[pos][rem][bada]!=-1)
		return dp[pos][rem][bada];
	int ans=0;
	if(bada==0){
		for(int j=0;j<=(s[pos]-'0');j++){
			ans= (ans+f(pos+1,(rem +j)%k,j<s[pos]-'0'))%hell;
		}
	}else{
		for(int j=0;j<=9;j++){
			ans=(ans+f(pos+1,(rem+j)%k,1))%hell;
		}
	}
	return dp[pos][rem][bada]=ans;
}
void solve(){
 	memset(dp,-1,sizeof dp);
    cin>>s;
     n = s.size();
    cin>>k;
    cout<<(f(0,0,0)-1+hell)%hell<<endl;
}
signed main()
{
    ios
    int test = 1;
    //cin>>test;
    while(test--){
    	solve();
    }
    return 0;
}
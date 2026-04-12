#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<int, int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repd(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<int> >
#define vll vector<int>
#define mint map<int,int> 
#define sz(x) (int)x.size()
#define sll set<int>
#define pll pair<int,int>
#define F first
#define S second

int n;
int arr[3005];
int dp[3005][3005];

int find(int l, int r){
	if(l>r)
		return -1;

	if(dp[l][r]!=-1)
		return dp[l][r];

	if(l==r){
		return dp[l][r] = arr[l];
	}

	else
		return dp[l][r] = max(arr[l]-find(l+1,r), arr[r]-find(l,r-1));

}

void solve(){
	
	cin>>n;
	rep(i,0,n)
		cin>>arr[i];

	memset(dp,-1,sizeof dp);
	cout<<find(0,n-1)<<endl;;
}
signed main(){
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand (static_cast <unsigned> (time(0)));
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vl vector<ll>
#define vi vector<int>
#define sl set<ll>
#define sc set<char>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mpi map<ll,ll>
#define mpc map<char,ll>
#define forn(i,n) for(ll i=0;i<n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inf        1000000000000

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	forn(i,n)
	cin>>a[i];
	ll dp[3005][3005]={0};
	for(ll i=n-1;i>=0;i--){
		for(ll j=i;j<n;j++){
			if(i==j){
				dp[i][j]=a[i];
			}
			else{
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1];
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}

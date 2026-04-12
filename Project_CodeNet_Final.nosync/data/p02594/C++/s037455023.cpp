#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define f first 
#define s second 
using namespace std;
const int N=5e6+10;
const int mod=1e9+7;
int arr[N],iarr[N];
int logi(int n){int p=0;while(n/2){n=n/2;p++;}return p;}
int poww(int x,int y){int pro=1;while(y){if(y&1)pro=((pro%mod)*(x%mod)%mod);y=y>>1;x=((x%mod)*(x%mod)%mod);}return pro;}
int poww2(int x,int y){int pro=1;while(y){if(y&1)pro=pro*x;y=y>>1;x=x*x;}return pro;}
double poww1(double x,int y){double pro=1.000000000;while(y){if(y&1)pro=((pro)*(x));y=y>>1;x=((x)*(x));}return pro;}
map<int,int> mp1,mp2;
set<int> st;
int arr1[1000001],arr2[1000001];
/*

*/
void solve()
{
	int x;
	cin>>x;
	if(x>=30) cout<<"Yes";
	else cout<<"No";
}

int32_t main()																																	
{
	fast;
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

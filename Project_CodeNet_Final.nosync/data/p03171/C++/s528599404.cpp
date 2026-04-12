#include<bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define F(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define VE(i,v) for(int i = 0;i < (v).size();i++)

using namespace std;
#define trace(...) cerr<<__FUNCTION__<<":"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cerr<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cerr.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned int ui;
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
typedef pair<ll,ll> pll;
typedef vector<pll> vpll; 
 
vector<int> id;
vector<int> od;
vi adj[100001];

ll dp[3001][3001][2];
int N;
ll helper(int p, int i, int j, vector<ll> &arr)
{
	if((i>=N) || (j<0) || (i>j))
		return 0;
	if(dp[i][j][p]==-1e18)
	{
		if(p==0)
			dp[i][j][0] = max(arr[i]-helper(1,i+1, j, arr), arr[j]-helper(1,i,j-1, arr));
		else
			dp[i][j][1] = max(arr[i]-helper(0,i+1, j, arr), arr[j]-helper(0,i,j-1, arr));
	}
	return dp[i][j][p];
}


int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	T=1;

	for(int tc=1; tc<=T;tc++)
	{
		cin >> N; 
		for(int i=0; i <=N; i++)
			for(int j=0; j<=N; j++)
				for(int k=0; k<2; k++)
					dp[i][j][k] = -1e18;

		vector<ll> arr(N+1);
		for(int i=0; i <N; i++)
		{
			cin>>arr[i];
			dp[i][i][0] = arr[i];
			dp[i][i][1] = arr[i];
		}
		ll ans = helper(0,0, N-1, arr);

		


			
		
		cout<<ans<<"\n";
	}
 
 
 
	return 0;
}
 
 


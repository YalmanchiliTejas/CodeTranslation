#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define loop(i,s,e) for(int i=s; i<e; i++)
#define endl '\n'
#define vii vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define N 100001
#define pb push_back
#define INF LLONG_MAX
#define inf INT_MAX

void INP();

#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define rtn                                       if(0)return;
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { rtn cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{     rtn 
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
int arr[3001];
int dp[3001][3001][3];

int util(int f, int b, int player){
	if(f>b) return 0;

	if(dp[f][b][player]!=-1) return dp[f][b][player];

	if(player==1){
		int p = arr[f]+util(f+1, b, 3-player);
		int q = arr[b]+util(f, b-1, 3-player);
		return dp[f][b][player] = max(p, q);
	}
	
	int c = util(f+1, b, 3-player)-arr[f];
	int d = util(f, b-1, 3-player)-arr[b];
	return dp[f][b][player] = min(c, d);

}

void alpha()
{	

	memset(dp, -1, sizeof(dp));

	int n;
	cin>>n;

	loop(i,0,n) cin>>arr[i];

	// for(int i=0; i<n; i++) cout<<arr[i]<<" ";

	// cout<<"hello"<<endl;

	cout<<util(0, n-1, 1)<<endl;
}

int32_t main(){

	ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//INP();
    int t=1;
	//cin>>t;

  	while(t--) alpha();

	return 0;

}






















inline void INP()
{
      #ifndef ONLINE_JUDGE
          freopen("input.txt",  "r",  stdin);
          freopen("output.txt", "w", stdout);
      #endif
}
 
 
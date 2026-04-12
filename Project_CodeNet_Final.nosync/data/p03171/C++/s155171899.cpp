#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define sz(v) (int) v.size()
#define pr(v) For(i, 0, sz(v)) {cout<<v[i]<<" ";} cout<<endl;
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000007
#define INF 1000000000000000007LL

const int N = 100005;
 
// it's swapnil07 ;)
 
#ifdef SWAPNIL07
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

int dp[3005][3005][2];

signed main()
{
    fast
    #ifdef SWAPNIL07
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin>>n;
    int arr[n];
    For(i, 0, n){
    	cin>>arr[i];
    	dp[i][i][1]=arr[i];
    	dp[i][i][0]=0;
    }
    int pre[n];
    pre[0]=arr[0];
    For(i, 1, n){
    	pre[i]=pre[i-1]+arr[i];
    }
    for(int len=1; len<n; len++){
    	for(int i=0; i<n-len; i++){
    		int j = i+len;
    		int tot = 0;
    		if(i==0)
    			tot = pre[j];
    		else
    			tot = pre[j]-pre[i-1];
    		dp[i][j][1]=max(dp[i][j-1][0]+arr[j], dp[i+1][j][0]+arr[i]);
    		dp[i][j][0]=tot-dp[i][j][1];
    	}
    }
    cout<<dp[0][n-1][1]-dp[0][n-1][0];
    return 0;
}




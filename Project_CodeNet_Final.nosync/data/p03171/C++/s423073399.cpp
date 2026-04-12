#include <bits/stdc++.h>
using namespace std; 
  
typedef long long int ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pll> vll; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
typedef priority_queue <ll> pqb;
typedef priority_queue <ll, vector<ll>, greater<ll>> pqs;
double EPS = 1e-9; 
long long INF = 1000000000000000005ll; 
double PI = acos(-1); 
#define M 1000000007ll
#define D 998244353ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound  
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define GCD(a,b) __gcd(a,b)
#define setbits(x)   __builtin_popcountll(x)
#define zerobits(x)  __builtin_ctzll(x) 
#define ps(x,y)  fixed<<setprecision(y)<<x
#define endl '\n'
#define ff first 
#define ss second 
#define mp make_pair  
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define PERMUTE next_permutation 
  
inline string IntToString(ll a) 
{ 
    char x[100]; 
    sprintf(x, "%lld", a); 
    string s = x; 
    return s; 
} 
  
inline ll StringToInt(string a) 
{ 
    char x[100]; 
    ll res; 
    strcpy(x, a.c_str()); 
    sscanf(x, "%lld", &res); 
    return res; 
} 
  
 
inline string uppercase(string s) 
{ 
    int n = SIZE(s); 
    for(ll i=0;i<n;i++) 
    if (s[i] >= 'a' && s[i] <= 'z') 
        s[i] = s[i] - 'a' + 'A'; 
    return s; 
} 
  
inline string lowercase(string s) 
{ 
    int n = SIZE(s); 
    for(ll i=0;i<n;i++) 
    if (s[i] >= 'A' && s[i] <= 'Z') 
        s[i] = s[i] - 'A' + 'a'; 
    return s; 
}

bool cmp(pll a,pll b)
{
  ll as=a.ff-a.ss;
  ll bs=b.ff-b.ss;
    return (as>bs);
}

ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};

vl v[100005];
vector <bool> vis(100005);
ll ma=0;
void dfs(ll u,ll d){
	//vis[u]=1;
	ma=max(ma,d);
	for(int ch:v[u]){
			dfs(ch,d+1);
	}
}
ll dp[3004][3004];
ll a[3004];
ll solve(ll l,ll r,ll &n){
	if(l>n || r<0){
		return 0;
	}
	if(dp[l][r]>0){
		return dp[l][r];
	}
	//dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
	return dp[l][r]=max(a[l]-solve(l+1,r,n),a[r]-solve(l,r-1,n));
}

int main() {
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   	ll n;
   	cin>>n;
   	for(ll i=0;i<n;i++){
   		cin>>a[i];
   	}
   	for(ll i=0;i<n;i++){
   		dp[i][i]=a[i];
   	}
   	cout<<solve(0,n-1,n)<<endl;
    return 0; 
}
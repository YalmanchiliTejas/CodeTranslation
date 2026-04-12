#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define mod 1000000007
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dx8[]={1,-1,0,0,1,1,-1,-1};
int dy8[]={0,0,1,-1,1,-1,1,-1};

ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinvfermat(ll a, ll m)
{
	return binexp(a, m - 2, m);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}
// ll n,m;
// ll c;

// vector<ll> v[200001];
// ll vis[200001];
// void dfs(ll node){
// 	vis[node]=1;
// 	c++;

// 	for(auto i:v[node]){
// 		if(vis[i]==0){
			

// 			dfs(i);

// 		}
// 	}
// }
ll sumi(ll a[], ll n) 
{ 
    
    map<ll, ll> cnt; 
  
    // Traverse in the list from start to end 
    // number of times a[i] can be in a pair and 
    // to get the difference we subtract pre_sum. 
    ll ans = 0, pre_sum = 0; 
    for (ll i = 0; i < n; i++) { 
        ans += (i * a[i]) - pre_sum; 
        pre_sum += a[i]; 
  
        // if the (a[i]-1) is present then 
        // subtract that value as f(a[i], a[i]-1)=0 
        if (cnt[a[i] - 1]) 
            ans -= cnt[a[i] - 1]; 
  
        if (cnt[a[i] + 1]) 
            ans += cnt[a[i] + 1]; 
  
        // keeping a counter for every element 
        cnt[a[i]]++; 
    } 
    return ans; 
} 
void  findProductSum(ll  a[], ll  n) 
{ 
     
        int sum = 0 ;
        
        int dp[n];
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = sum;
            sum=(sum%mod+a[i]%mod)%mod;
        }
        
        sum = 0 ;
        
        for(int i=0;i<n;i++)
        {
            sum =(sum%mod+ a[i]%mod*dp[i]%mod)%mod;
        }
        
        cout<<sum<<endl;
} 

void solve(){
	
	ll   n;
	cin>>n;
	ll  a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];

	}
	findProductSum(a,  n); 
	










return;
}




int main()
{  
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    fast;
    ll t;
    t=1;
   //cin>>t;
    while(t--){
    	solve();
    }
    
   
  



#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
return 0;
}
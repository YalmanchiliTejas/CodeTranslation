#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
//for set
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;   
// for multiset
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;

#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535897932384626433832795
int MOD=1e9+7;
int powmod(int a,int l, int md){int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
int binpow(int a,int l){int res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
int __set(int b, int i) {return b|(1<<i);} //set ith bit
int __unset(int b, int i) {return b&(~(1UL<<i));}
int __check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
int mulmod(int a, int b, int md) {return ((a%md)*(b%md))%md;}
int addmod(int a, int b, int md) {return (a+b)%md;}
int submod(int a, int b, int md) {return (((a-b)%md)+md)%md;}
int divmod(int a, int b, int md) {return mulmod(a, powmod(b, md-2, md), md);} //if md is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
int dp[100][100000];

int32_t main(void)
{
	IOS;
	string k; int d;
	cin>>k>>d;
	int n = k.length();
	vi a(n+1);
	for(int i = 0; i < n; i++)
		a[i+1]=k[i]-'0';
	for(int i = 0; i < 10; i++) {
		if(n==1 && i==0)
			continue;
		dp[(i%d)][1]++;
	}
	// for(int i = 0; i < d; i++) {
	// 	for(int j = 1; j <= n; j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < d; j++) {
			for(int k = 0; k < 10; k++) {
				if(i==n-1 && k == 0)
					continue;
				// cout<<k<<endl;
				// cout<<j<<" "<<k<<" "<<(j+k)%d<<" "<<dp[j][i]<<endl;
				dp[(j+k)%d][i+1]+=dp[j][i];
				dp[(j+k)%d][i+1]%=MOD;
			}
		}
	}
	// for(int i = 0; i < d; i++) {
	// 	for(int j = 1; j <= n; j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	int ans=0, rem=0;
	for(int i = 1; i <= n; i++) {
		if(i==n) {
			// cout<<"in1 "<<rem<<endl;
			for(int j = 0; j <= a[i]; j++) {
				// if(i==1 && j==0)
				// 	continue;
				if((rem+j)%d==0) {
					// cout<<"in"<<endl;
					ans = (ans+1)%MOD;
				}
			}
		}
		else {
			for(int j = 0; j < a[i]; j++) {
				// if(i==1 && j==0)
				// 	continue;
				// cout<<j<<" "<<((d-rem-j)%d+d)%d<<" "<<n-i<<" "<<dp[((d-rem-j)%d+d)%d][n-i]<<endl;
				ans += dp[((d-rem-j)%d+d)%d][n-i];
				ans %= MOD;
			}
		}
		rem += a[i];
		rem %= d;
	}
	// if(rem%d==0) ans++;
	ans = (ans-1+MOD)%MOD;
	cout<<((ans+MOD)%MOD)<<endl;
	time();
	return 0;
}
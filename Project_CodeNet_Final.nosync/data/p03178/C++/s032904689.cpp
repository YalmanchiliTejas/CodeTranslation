/*"You can do anything you set your mind to,man" - Eminem*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define llpow(a,b) (ll)(pow(a,b)+0.5)
#define l_b(a,val) min((int)a.size()-1, (int)(lower_bound(a.begin(),a.end(),val)-a.begin()))
#define f first
#define up(a,b) max(a,b)
#define s second
#define INF 9223372036854775807
const  int mod = 1000000007;
template <typename T> T add(T& a, T b){a+=b;while(a>=mod)a-=mod;while(a<0)a+=mod;}
template <typename T> T mul(T& a, T b){ a = a*b%mod;}
template <typename T> T up_self(T& a, T b){a = up(a,b);}
template <typename T> T min_self(T& a, T b){a = min(a,b);}
ll binexpomodulo(ll x, ll y){ll res =1;x%=mod;if(!x)return 0;while(y){if(y&1){mul(res, x);}mul(x,x);y>>=1;}return res;}
ll nCrInOr(ll n, ll r){ll res = 1;if(r>n-r)r = n-r;ll rin = 1;for(ll i = 1; i <=r ; i++)rin = (rin*i)%mod;rin = binexpomodulo(rin,mod-2);for(ll i = 1; i <= r; i++)res = (res*(n-i+1))%mod;res = (res*rin)%mod;return res;}
int msb(ll n){int ans;for(int i = 0 ; i < 64;  i++)if(n&(1LL<<i))ans = i+1;return ans;}
/*All the macros below are copied from nik_y(OG)*/
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define get(a,n) fl(i,0,n)  cin>>a[i];
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
int main()
{
	Shazam;
	string k; cin>>k;
	int d; cin>>d;

	vector<vector<int>> dp(d,vector<int>(2));
	dp[0][0] = 1;
	for(int i = 0 ; i < k.length(); i++){
		vector<vector<int>> new_dp(d,vector<int>(2));
		for(int sum = 0 ; sum<d; sum++){
			for(bool smaller_already : {false,true}){
				for(int digit = 0; digit<10 ; digit++){
					if(digit>k[i]-'0'&&!smaller_already)
						break;
					add(new_dp[(sum+digit)%d][smaller_already||k[i]-'0'>digit], dp[sum][smaller_already]);
				}
			}
		}
		dp = new_dp;
	}
	ll ans = (dp[0][0]+dp[0][1])%mod;
	ans--;
	if(ans==-1)
		ans = mod-1;
	cout<<ans<<endl;
  	return 0;
}
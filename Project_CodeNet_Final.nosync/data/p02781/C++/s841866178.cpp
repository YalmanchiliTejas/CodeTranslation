#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
//for set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;   
// for multiset
// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update> ordered_multiset;

#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define PI 3.1415926535897932384626433832795
int MOD=1e9+7;
// int MOD=998244353;
int powmod(int a,int l, int md){int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
int binpow(int a,int l){int res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> ii; typedef vector<ii> vii;
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

int cmp(const ii& p1, const ii& p2) {
	return (p1.ss>p2.ss);
}
const int MX = 110;

int f[MX];
int rf[MX];

int C(int l,int k, int md) 
{
    if (k<0||k>l){
        return 0;
    }
    return f[l]*rf[k]%md*rf[l-k]%md;
}

void precfac() {
    f[0]=1;
    for (int i=1;i<MX;i++){
        f[i]=f[i-1]*i%MOD;
    }
    rf[MX-1]=powmod(f[MX-1],MOD-2, MOD);
    for (int i=MX-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%MOD;
    }
}
signed main(void)
{
	IOS;
	precfac();
	string s;
	int k; cin>>s>>k;
	int n=s.length();
	int ans=0;
	// cout<<n<<" "<<k<<endl;
	// cout<<C(0,0,MOD)<<endl;
	ans += (C(n-1,k,MOD)*powmod(9ll,k,MOD))%MOD;
	// cout<<ans<<endl;
	int cnt=0;
	for(int i = 0; i < n; i++) {
		if(s[i]!='0')
			cnt++;
	}
	for(int i = 1; i < s[0]-'0'; i++) {
		ans += (C(n-1,k-1,MOD)*powmod(9ll,k-1,MOD))%MOD;
		ans %= MOD;
	}
	// cout<<ans<<endl;
	if(k==1) {
		// if(cnt==k)
		ans++;
		ans%=MOD;
		cout<<ans<<endl;
		return 0;
	}
	if(k==3) {
		for(int i = 1; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				for(int l = 1; l <= 9; l++) {
					for(int m = 1; m<=9; m++) {
						string tp="";
						tp.pb(s[0]);
						for(int o = 1; o < n; o++) {
							if(o==i)
								tp.pb(l+'0');
							else if(o==j)
								tp.pb(char(m+'0'));
							else
								tp.pb('0');
						}
						if(tp <= s) {
							// cout<<tp<<endl;
							ans++;
							if(ans >= MOD)
								ans %= MOD;
						}
					}
				}
			}
		}
	}
	if(k==2) {
		for(int i = 1; i < n; i++) {
			for(int l = 1; l <= 9; l++) {
					string tp="";
					tp.pb(s[0]);
					for(int o = 1; o < n; o++) {
						if(o==i)
							tp.pb(char(l+'0'));
						else
							tp.pb('0');
					}
					if(tp <= s) {
						// cout<<tp<<endl;
						ans++;
						if(ans >= MOD)
							ans %= MOD;
					}
			}
		}
	}
	cout<<ans%MOD<<endl;
	time();
	return 0;
}
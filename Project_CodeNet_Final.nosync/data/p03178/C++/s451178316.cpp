#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n,d) for(int i=n;i>=d;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000009
#define inff 0x3f3f3f3f
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<lli>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	int d;string s;
	cin>>s>>d;
	int l=s.length();
	lli dp[d+5][2];
	mem(dp,0);
//	for(char c='0';c<=s[0];c++){
//		dp[c-'0'][c-'0']++;
//	}
	dp[0][0]=1;
	FORQ(0,l-1){
		lli ndp[d+5][2];
		mem(ndp,0);
		for(lli sm=0;sm<d;sm++){
			for(int pr=0;pr<2;pr++){
				for(int cur=0;cur<10;cur++){
					if(cur>s[i]-'0'&&pr==0) break;
					ndp[(sm+cur)%d][pr||cur<s[i]-'0']=(ndp[(sm+cur)%d][pr||cur<(s[i]-'0')]+dp[sm][pr])%mod;
				}
			}
		}
		for(int j=0;j<d;j++){
			for(int k=0;k<2;k++){
				dp[j][k]=ndp[j][k];
			}
		}
	}
	lli an=0;
	for(int i=0;i<2;i++){
		an=(an+dp[0][i])%mod;	
	}
	an=(an-1+mod)%mod;
	cout<<an;
}


#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i,a,b) for (int i = a; i > b; --i)
#define mm(lamb, tttt) memset(lamb, tttt, sizeof lamb)
 
#define null NULL
#define eps 0.000000001
#define mod 1000000007
#define mod1 998244353
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define sz(V) (int)V.size()
#define _ <<" "<<
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair <int, int> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<ii> vii;
ll dp[100005][2][105];
int d;
string s;

ll digit_dp(int index,int flag,int sum )
{
	//cout<<index _ flag _ sum<<endl;
	if(index == s.length())
	{
		if(sum ==0 )
		{
			return 1;
		}
		return 0;
	}

	if(dp[index][flag][sum] != -1)
	{
		return dp[index][flag][sum];
	}

	int limit = 9;
	if(flag)
	{
		limit = s[index ] -'0';
	}
	ll ans = 0;
	
	for(int i=0;i<=limit;i++)
	{
		bool nf ;
		if(i < limit)
		{
			nf = 0;
		}
		else{
			nf = flag;
		}
		ans += digit_dp(index+1 ,nf,((sum + i)%d) % mod);
		ans %= mod;
	}

	dp[index][flag][sum] = (ans%mod);
	return (ans%mod);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
 
	//freopen ("test.txt","r",stdin);
	memset(dp, - 1, sizeof(dp));
	cin>>s;
	cin>>d;

	cout<<(( (digit_dp(0,1,0)- 1) + mod) % mod);

} 
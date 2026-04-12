       
   //                                                  '-.-'
   //                                         ()      __.'.__
   //                                      .-:--:-.  |_______|
   //                               ()      \____/    \=====/
   //                               /\      {====}     )___(
   //                    (\=,      //\\      )__(     /_____\
   //    __    |'-'-'|  //  .\    (    )    /____\     |   |
   //   /  \   |_____| (( \_  \    )__(      |  |      |   |
   //   \__/    |===|   ))  `\_)  /____\     |  |      |   |
   //  /____\   |   |  (/     \    |  |      |  |      |   |
   //   |  |    |   |   | _.-'|    |  |      |  |      |   |
   //   |__|    )___(    )___(    /____\    /____\    /_____\
   //  (====)  (=====)  (=====)  (======)  (======)  (=======)
   //  }===={  }====={  }====={  }======{  }======{  }======={
   // (______)(_______)(_______)(________)(________)(_________)
   //
   // Credits :- Joan G. Stark
   //|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
   //|                      AUTHOR - KASPAROVIAN                                     |
   //|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fr first
#define sc second
#define mk make_pair
#define endl '\n'
#define int long long
#define MOD 1000000007
#define in insert
#define sz(x) (ll)(x).size()
#define mem(a,b) memset(a,b,sizeof(a))
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef vector<vi> graph;
template<class T> void mxi(T & a, const T & b) { a = max(a, b); }
template<class T> void mni(T & a, const T & b) { a = min(a, b); }
ld EPS=1e-9;
int n;
int dp[3100][3100][2];
int arr[3100],suf[3100];
int go(int st,int ed,int par)
{
	if(st==ed)
		return dp[st][ed][par]=arr[st];
	if(dp[st][ed][par]!=-1)
		return dp[st][ed][par];
	int &s=dp[st][ed][par];
	s=max(arr[st]+suf[st+1]-suf[ed+1]-go(st+1,ed,(par+1)%2),arr[ed]+suf[st]-suf[ed]-go(st,ed-1,(par+1)%2));
	return s;
}
void solve()
{
	mem(dp,-1);
	cin>>n;
	int sum=0;
	frr(i,n)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	suf[n]=0;
	for(int i=n-1;i>=0;i--)
		suf[i]=suf[i+1]+arr[i];
	cout<<2*go(0,n-1,0)-sum<<endl;

}
signed main()
{
  fast;
  int t,tab;
  t=1;
  tab=t;
  while(t--)
  {
    //cout<<"Case #"<<(tab-t)<<": ";
    solve();
  }
}
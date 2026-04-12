       
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
#define MOD 1000000007
#define in insert
#define sz(x) (ll)(x).size()
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
typedef vector<vi> graph;
template<class T> void mxi(T & a, const T & b) { a = max(a, b); }
template<class T> void mni(T & a, const T & b) { a = min(a, b); }
ld EPS=1e-9;
string s;
int d;
int dp[10010][2][2][101];
int go(int lv,int t1,int t2,int rem)
{
	if(lv==s.size()&&rem==0)
		return 1;
	else if(lv==s.size())
		return 0;
	int &e=dp[lv][t1][t2][rem];
	if(e==-1)
	{
		e=0;
		int lw=0,hw=9;
		if(!t1)
		{
			if(lv==s.size()-1)
				lw=1;
		}
		if(!t2)
			hw=s[lv]-'0';
		int tt1=t1,tt2=t2;
		for(int i=lw;i<=hw;i++)
		{
			if(i>lw||t1)
				tt1=1;
			else
				tt1=0;
			if(i<hw||t2)
				tt2=1;
			else
				tt2=0;
			e=(e+go(lv+1,tt1,tt2,(rem+i)%d))%MOD;
		}
	}
	return e;
}
void solve()
{
  mem(dp,-1);
  cin>>s;
  cin>>d;
  cout<<go(0,0,0,0)<<endl;
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
//APPROACHING A QUESTION
//+ Think of binary search (max of min etc also if n<=2*10^5)
//+ Think of common dp states (Even if it appears as maths but constraints are small)
//+ Check constraints
//+ Keep calm and enjoy the question
//+ Be sure to remove MOD from binpow (if needed)
//+ Try bidirectional analysis for constructive questions
//+ If given some sequence try thinking of prefix sums
//+ If constraints are too large maybe its simple maths
//+ In questions with binary operations think of bits independently and also the change pattern
//+ If two or more binary operations are given mostly there is a relation between them and an arithmatic operator
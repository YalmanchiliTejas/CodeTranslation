       
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
void solve()
{
  int n;
  cin>>n;
  if(n<30)
  	cout<<"No\n";
  else
  	cout<<"Yes\n";

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
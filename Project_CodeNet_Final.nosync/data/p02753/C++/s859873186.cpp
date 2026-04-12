//naveen mall
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb               push_back
#define sz(c)            (int)c.size()
#define len(c)           (int)c.length()
#define vec              vector
#define int              long long int
#define all(c)           c.begin(), c.end()
#define rall(c)          c.rbegin(), c.rend()
#define trav(a,i)        for(auto i: a)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define invect(v,n)       for(int i=0;i<n;i++ ){int arb;cin>>arb;v.pb(arb);}
#define inset(s,n)        fl(i,0,n){int aset;cin>>aset;s.insert(aset);}
#define display(c)        trav(c,i) cout<<i<<" ";cout<<"\n";
#define F                 first
#define S                 second
#define pii               pair<int,int>
#define PB                pop_back
#define endl              "\n"
#define what(x) cerr << #x << " is " << x << endl;
int sum() { return 0; }template<typename T,typename... Args>T sum(T a, Args... args) { return a + sum(args...); }
#define p   998244353

void solve()
{ 

 string s;
  cin>>s;
  int f=0,g=0;

  rep(i,0,3)
  	  {
  	  	if(s[i]=='A')
  	  		f=1;
  	  	if(s[i]=='B')
  	  		g=1;
  	  }
  	  if(f and g)
  	  	  cout<<"Yes";
  	  	else
  	  		cout<<"No";











   
 }

  

signed main()
{fast
	int t;
	//cin>>t;
	t=1;
	while(t--)
		{solve();}
	
}











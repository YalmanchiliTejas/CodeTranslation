/********************************************************
     Failing doesn’t give you a reason to give up,
     as long as you believe.
                                  - Seventh Hokage
********************************************************/

#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define int long long int
typedef vector< int >        vi;
typedef set< int >           si;
typedef pair< int, int >     pii;
typedef map< int, int >      mii;
#define sz(a)           (int)((a).size())
#define pb              push_back
#define mp              make_pair
#define all(c)          (c).begin(),(c).end()
#define rall(c)         (c).rbegin(),(c).rend()
#define ub(c,k)         (upper_bound(all(c),k)-(c).begin())
#define lb(c,k)         (lower_bound(all(c),k)-(c).begin())
#define inf             LLONG_MAX
#define _inf            LLONG_MIN
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define fr(n)           for(int i=0;i<n;i++)
#define tr(a)           for(auto it=a.begin();it!=a.end();it++)
#define trr(a)          for(auto it=a.rbegin();it!=a.rend();it++)
#define find(c, x)      (c.find(x) != c.end())
#define M               1000000007
#define PI              3.1415926535897932384
#define F               first
#define S               second
#define accuracy(x)     cout<<fixed<<setprecision(x);
#define fuck            {cout<<-1;return;}
#define fasterBaby      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define elasped_time	1.0 * clock() / CLOCKS_PER_SEC
#define N               200005
int a[N],b[N],vis[N],ans=0;
vi cnt[N];
int sol[N],k=0;
int recur(int x)
{
	//cout<<x;
	int temp=a[x];
	if(vis[x]) return 0;
	vis[x]=1;
	for(auto t:cnt[x]) {temp+=recur(t);}
	ans+=temp;
	sol[k++] = x;
	return temp;
}

void basEkBaarAur()
{
	int x;
	cin>>x;
	cout<<(x>=30?"Yes":"No");
}

signed main()
{
	accuracy(15)
	fasterBaby
	int TESTS=1,i=1;
	//cin>>TESTS;
	while(TESTS--)
	{
		//cout<<"Case#"<<i++<<endl;
		basEkBaarAur();
		cout<<endl;
	}
	cerr<<endl<<"समय गुज़रा : "<<elasped_time<<endl;
	return 0;
}
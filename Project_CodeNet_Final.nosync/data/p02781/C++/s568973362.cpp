#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
//#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<vector<ll> > mat;

string s;
int n,k;
ll dp[4][305][2];

ll go(int on,int id,int nz)
{
	if(nz>k)return 0;
	if(id==n)
	{
		if(nz==k)return 1;
		return 0;
	}
	if(dp[nz][id][on]!=-1)return dp[nz][id][on];
	int st=0;
	int en=9;
	if(on==1)en=s[id]-'0';
	ll &r=dp[nz][id][on];
	r=0;
	rep(i,st,en)
	{
		int on2=on;
		if(i<en)on2=0;
		r+=go(on2,id+1,nz+(i>0));
	}
	return r;
}

int main()
{ios_base::sync_with_stdio(false);
cin>>s;
cin>>k;
n=s.length();
rep(i,0,3)rep(j,0,304)rep(k,0,1)dp[i][j][k]=-1;
ol(go(1,0,0));
return 0;
}


#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (int i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef long double lldb;
typedef pair<ll, ll>  ii;
typedef pair<lldb, lldb>  iidb;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const lldb PI = acos(-1);
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 55
#define offset 200
#define ptr nodo*
const ll MOD=1e9+7;
#define lazy first
#define sum second
ll N,X;
ll v[tam];
int dp[tam][tam];
int solve(int pos,int sumini)
{
	if (sumini<0)
		return 0;
	if (pos==N)
		return sumini==0;

	if (dp[pos][sumini]!=-1)
		return dp[pos][sumini];
	ll xi;
	int res=0;
	forr(i,0,N)
	{
		xi=v[pos]-i+X;
		//cout<<xi<<" "<<pos<<" "<<sumini<<endl;
		if (xi>=0 && xi%(N+1)==0 && sumini>=i)
		{
			res|=solve(pos+1,sumini-i);
		}
	}
	return dp[pos][sumini]=res;
}
int main()
{
	cin>>N;
	ll total=0;
	forr(i,0,N)
	{
		cin>>v[i];
		total+=v[i];
	}
	ll minn=1e18;
	forr(sum,0,N*(N-1)+1)
	{
		X=total-sum;
		memset(dp,-1,sizeof dp);

		if (solve(0,sum)==1)
		{
			
			minn=min(minn,X);
		}
	}
	cout<<minn<<endl;
}
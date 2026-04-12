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
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
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
#define initseg ll new_nodo=(pnodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 320000
#define offset 200
#define ptr nodo*
const ll MOD=1e9+7;
ll v[tam];
int main()
{
	int n;
	cin>>n;
	ll answer=0,tot=0;
	forr(i,0,n)
	{
		cin>>v[i];
		v[i]%=MOD;
		tot+=v[i];
		tot%=MOD;
	}
	forr(i,0,n)
	{
		tot-=v[i];tot%=MOD;tot+=MOD;tot%=MOD;
		answer+=((tot%MOD)*(v[i]%MOD));
		answer%=MOD;
	}
	cout<<answer<<endl;
}
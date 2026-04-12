#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define se second
#define fi first
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef vector<ll>  vi;
typedef pair<ii, ll>  iii;
typedef pair<double, double>  iidb;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const double PI = acos(-1);
#define initseg ll new_nodo=(nodo*2)+1,mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define offset 9000

const ll MOD=1e9+7;

#define cmplog 20
#define tam 600000


using namespace std;
ll pos[tam];
int main()
{	
	ios::sync_with_stdio(false);cin.tie(0);
	ll n,x,m;
	cin>>n>>x>>m;
	ll ciclo=x;
	set<ll> s;
	vector<ll> v;
	while(s.find(ciclo)==s.end())
	{
		
		s.insert(ciclo);
		pos[ciclo]=v.size();
		v.pb(ciclo);

		ciclo*=ciclo;ciclo%=m;
		
		
	}
	//cout<<ciclo<<" "<<pos[ciclo]<<endl;
	ll ini=pos[ciclo],j=0;
	ll valor=0;
	while(n>0 && j<ini)
	{
		valor+=v[j];j++;
		n--;
	}

	if (n==0){cout<<valor<<endl;return 0;}
	ll l=v.size()-ini;
	ll vueltas=(n/l),completo=0;
	forr(i,ini,v.size())completo+=v[i];
	//cout<<vueltas<<' '<<completo<<endl;
	valor+=vueltas*completo;

	forr(i,0,n%l)
		valor+=v[ini+i];
	cout<<valor<<endl;

		

}
#include <bits/stdc++.h>
using namespace std;
#define iof freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BiEdge(v,a,b) (v)[(a)].pb((b)),(v)[(b)].pb((a))
#define ll long long
#define ld long double
#define pb push_back
#define Pb pop_back
#define F first
#define S second
#define pi acos(-1)
#define eps 1e-7
#define bpc __builtin_popcount
#define all(f) (f).begin(),(f).end()
#define allr(f) (f).rbegin(),(f).rend()
#define cross(a,b) (conj(a)*(b)).real()
#define dot(a,b) (conj(a)*(b)).imag()
typedef complex <ld> point ;
typedef vector <point> polygon ;
typedef tuple <ll,ll,ll> line ;
const int mod = 1e9+7 , A = 1e5+5 ;

ll rep[100005] , sz[100005] ;
ll find(ll u)
{
	return rep[u] == u ? u : rep[u] = find(rep[u]) ;
}
bool join(ll a , ll b)
{
	a = find(rep[a]) , b = find(rep[b]) ;
	if (a == b)
		return false ;
	if (sz[a] < sz[b])
		swap (a , b) ;
	sz[a] += sz[b] , sz[b] = 0 ;
	rep[b] = a ;
	return true ;
}
int main()
{
	ios
	ll n;
	cin >> n;
	for(int i = 0;i<n;i++)
		rep[i] = i,sz[i] = 1;
	pair<ll,ll>arr[n+1];
	vector<pair<ll,pair<ll,ll>>>byX,byY;
	for(int i = 0;i<n;i++)
		cin >> arr[i].F >> arr[i].S,byX.pb({arr[i].F,{arr[i].S,i}}),byY.pb({arr[i].S,{arr[i].F,i}});
	sort(all(byX)),sort(all(byY));
	map<ll,vector<pair<ll,ll>>>mp;
	for(int i = 1;i<n;i++)
	{
		mp[byX[i].F - byX[i-1].F].pb({byX[i].S.S,byX[i-1].S.S});
		mp[byY[i].F - byY[i-1].F].pb({byY[i].S.S,byY[i-1].S.S});
	}
	ll ans = 0;
	for(auto i:mp)
		for(auto j:i.S)
			if(join(j.F,j.S))
				ans+=i.F;
	cout << ans;
	return 0 ;
}

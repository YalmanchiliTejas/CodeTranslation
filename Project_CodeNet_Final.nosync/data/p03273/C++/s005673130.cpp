#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define M 1000000 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(ll i = a; i<=b; ++i)
#define NFOR(i,a,b) for(ll i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const ll N = 1e5 + 10;
inline ll add(ll x,ll y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline ll mul(ll x,ll y){
  x = (1LL * x * y) % mod;
  return x;
}


int main()
{
	fast;

	int h,w;cin>>h>>w;
	char mat[101][101];
	int flg1[101] = {0};
	int flg2[101] = {0};
	FOR(i,1,h)FOR(j,1,w)cin>>mat[i][j];
	FOR(i,1,h){
		int flag = 1;
		FOR(j,1,w)if(mat[i][j] == '#')flag = 0;
		flg1[i] = flag;
	}
	FOR(i,1,w){
		int flag = 1;
		FOR(j,1,h)if(mat[j][i] == '#')flag = 0;
		flg2[i] = flag;
	}	

	FOR(i,1,h){
		FOR(j,1,w){
			if(flg1[i]==0 && flg2[j]==0)cout << mat[i][j];
		}
		if(flg1[i]==0)
		cout << "\n";
	}

	return 0;
}
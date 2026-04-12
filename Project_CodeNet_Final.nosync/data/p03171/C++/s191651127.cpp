#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl

vector < vector <bool> > visto(3005,vector<bool>(3005,false));
vector < vector <ll> > dp(3005,vector<ll>(3005,0));

ll juego(int x, int y, vector <ll> &v)
{
	if(visto[x][y]==true) return dp[x][y];
	visto[x][y]=true;
	if(x==y) 
	{
		dp[x][y]=v[x];
		return dp[x][y];
	}
	dp[x][y]=max(v[x]-juego(x+1,y,v),v[y]-juego(x,y-1,v));
	return dp[x][y];
}

 
int main()
{ 
	FIN;
	
	#ifdef input
		freopen("test2.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	vector <ll> v(n);
	forn(i,n) cin >> v[i];
	if(n==1) {cout << v[0] << endl; return 0;}
	cout << max(v[0]-juego(1,n-1,v),v[n-1]-juego(0,n-2,v)) << endl;
	//forn(i,n) forn(j,n) {cout << dp[i][j] << " "; cout << endl;}
	
	return 0;
}

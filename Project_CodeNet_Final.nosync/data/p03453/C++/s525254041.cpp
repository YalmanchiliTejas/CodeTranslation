#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;
typedef long double DB;

const ll N = 100100;
const ll MOD = 1000*1000*1000LL + 7 , INF = MOD*N;


vector <pii> adj1[N];
vector <int> q , par[N] , adj2[2][N];
set <pii> s;

ll num[2][N] , d[2][N] , ans;
int n , m , b , e , deg[N];


void Dijkstra(int st , bool f){

	for(int i = 0 ; i < n ; i++){
	   if(i != st)
		  d[f][i] = INF;
	   s.insert({d[f][i] , i});
	}   

	while(s.size()){

		int v = (*s.begin()).S;
		s.erase(s.begin());

		for(auto u : adj1[v]){
		   ll c = d[f][v] + u.S;
		   if(c < d[f][u.F]){
			  s.erase({d[f][u.F] , u.F});
			  d[f][u.F] = c;
			  s.insert({c , u.F});
		   }
		}

	}

	return;

}


void tsort(int st , bool f){
	
	for(int i = 0 ; i < n ; i++)
	   deg[i] = adj2[1-f][i].size();

	
	num[f][st] = 1;
	q.pb(st);

	int pt1 = 0 , pt2 = 1;

	while(pt1 < pt2){
		
	   for(int u : adj2[f][q[pt1]]){
		  deg[u]--;
		  if(!deg[u])
			 q.pb(u) , pt2++;
	   }

	   pt1++;
	}

	for(int v : q)
	   for(int u : adj2[f][v])
		  num[f][u] = (num[f][u] + num[f][v]) % MOD;
	
	q.clear();
	return;
}


int main(){

	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	
	int u , v , w;

	cin >> n >> m >> b >> e;
	b-- , e--;	

	for(int i = 0 ; i < m ; i++){
	   cin >> u >> v >> w;

	   adj1[--u].pb({--v , w});
	   adj1[v].pb({u , w});
	}

	Dijkstra(b , 0);
	Dijkstra(e , 1);	

	for(int i = 0 ; i < n ; i++){
	   for(auto u : adj1[i]){
		  if(d[0][i] + d[1][u.F] + u.S == d[0][e]){
			 adj2[0][i].pb(u.F);
			 adj2[1][u.F].pb(i);
		  }
	   }
	}

	tsort(b , 0);
	tsort(e , 1);

	ans = num[0][e] * num[0][e] % MOD;
	DB x = (DB) d[0][e]/2;

	for(int i = 0 ; i < n ; i++){
	   for(int u : adj2[0][i]){
		  ll y = num[1][u] , z = num[0][i];
		  if((DB) d[0][u] > x && (DB) d[0][i] < x)
			 ans -= (y*y % MOD)*(z*z % MOD) %MOD;
		  
		  ans = (ans + MOD) % MOD;
	   }
	   
	   if((DB) d[0][i] == x && d[1][i] == x){
		  ll z = num[0][i] , y = num[1][i];
	   	  ans -= (z*z % MOD)*(y*y % MOD) % MOD;
	   }

	   ans = (ans + MOD) % MOD;
	}

	cout << ans << endl;

}
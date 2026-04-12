//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;

int memo[10007][2][106];

str K; int D,N;

int solve(int u, int st, int mod){
	if(u==N && mod==0) return 1;
	if(u==N) return 0;
	if(memo[u][st][mod]!=-1) return memo[u][st][mod];

	int ans=0;
	for(int i=0; i<K[u]-'0'; i++) ans+=solve(u+1,1,(mod+i)%D),ans%=MOD;
	ans=(ans+solve(u+1,st,(mod+K[u]-'0')%D))%MOD;
	for(int i=K[u]-'0'+1; i<10 && st==1; i++) ans=(ans+solve(u+1,1,(mod+i)%D))%MOD;

	return memo[u][st][mod]=ans;
}



int32_t main(){
   boost;
   IO();

   cin>>K>>D;
   N=sz(K);
   for(int i=0; i<=N; i++) for(int j=0; j<=101; j++) memo[i][0][j]=memo[i][1][j]=-1;
   
   cout << (solve(0,0,0)-1+MOD)%MOD << endl;

   

   return 0;
}


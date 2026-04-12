#include <bits/stdc++.h>
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#define fst first
#define snd second
#define fore(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define bs binary_search
#define mm(a,b) memset(a,b,sizeof(a))
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int) (n).size())
#define MAXI ((ll)1e16)
#define MINI ((ll)-1e16)
using namespace std;
typedef long long ll;  
const long long M = 1e9 +7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }        
string s;
ll d;
ll dp[10000][100][2];
ll solve(int i, int res, int k){
	if(i==SZ(s) && res == 0)return 1;
	if(i==SZ(s))return 0;
	ll &r = dp[i][res][k];
	if(~r)return r;
	r = 0;
	if(!k){
		fore(j,0,10){
			r=(r+solve(i+1,(res+j)%d,k))%M;
		}
	}else{
		fore(j,0,(s[i]-'0')+1){
			r=(r+solve(i+1,(res+j)%d,j==(s[i]-'0')))%M;
		}
	}
	return r;
}


int main(){FIN;
	cin >> s >> d;
	mm(dp,-1);
	cout << (solve(0,0,1)-1+M)%M;
}
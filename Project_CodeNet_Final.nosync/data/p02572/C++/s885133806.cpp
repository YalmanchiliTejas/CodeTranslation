//(bool) ? (if true) : (if false)
//63LL - __builtin_clzll(n)
//(x&-x)
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pf push_front
#define sz size()
#define FORN(i,j,n) for(long long i=j; i<(long long)n;i++) 
#define FOR(i,n) FORN(i,0,n)
#define FORIT(i,x) for( auto i = x.begin() ; i != x.end() ; i++ )
#define LIM 262150
#define ones(x) __builtin_popcount(x)
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
using namespace std;
 
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
const ll MAX = 2e5+5;
const ll MOD = 1e9+7;
int n;
ll arr[MAX];
ll sum = 0;
ll ans = 0;
ll a ;
int main() {
	fastio;
	cin >> n;
	FOR(i,n) cin>> arr[i];
	FOR(i,n) sum = (sum + arr[i])%MOD;
	sum = sum*sum;
	sum = sum%MOD;
	ans += sum;
	FOR(i,n){
		arr[i] = arr[i]%MOD;
        a = arr[i]*arr[i];
		a = a %MOD;
        ans -= a;
        ans += MOD;
        ans = ans % MOD;		
	} 
	if(ans%2 == 1){ 
	    ans += MOD;
        ans /=2;
        ans = ans%MOD;
        cout<< ans << '\n';
		return 0;
    }		 
	cout<< (ans>>1) << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 3000+1;
ll memo[maxn][maxn][2];
int seen[maxn][maxn][2];
int N,A[maxn];

ll dp(int i,int j,int cnt){
	if(i == j){
		if(!cnt)return A[i];
		else return -A[i];
	}
	ll &res = memo[i][j][cnt];
	if(seen[i][j][cnt])return res;
	seen[i][j][cnt] = 1;
	if(cnt == 0){
		res = max(A[i]+dp(i+1,j,!cnt),A[j]+dp(i,j-1,!cnt));
	}else{
		res = min(-A[i]+dp(i+1,j,!cnt),-A[j]+dp(i,j-1,!cnt));
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,maxn)forn(j,0,maxn)forn(k,0,2){
		memo[i][j][k] = 0;
		seen[i][j][k] = 0;
	}
	cin >> N;
	forn(i,0,N)cin >> A[i];
	cout << dp(0,N-1,0) << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/

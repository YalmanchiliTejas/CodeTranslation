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

const ll mod = 1000000000+7;
const int maxn = 10000+1;
const int maxd = 100+1;
ll memo[maxn][2][maxd];
string str; 
int D;

ll dp(int pos,int menor,int m){
	if(pos >= str.size()){
		if(m == 0)return 1;
		return 0;
	}
	int limit = (menor) ? 9 : (str[pos]-'0');
	ll &res = memo[pos][menor][m];
	if(res != -1)return res;
	res = 0;
	for(int i = 0; i <= limit; i++){
		int newMenor = (menor) ? menor : (i == (str[pos]-'0')) ? 0 : 1;
		res += dp(pos+1,newMenor,(m+i)%D);
		res %= mod;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,maxn)forn(j,0,2)forn(k,0,maxd)memo[i][j][k] = -1;
	cin >> str >> D;
	ll res = dp(0,0,0); res--;
	if(res < 0)res += mod;
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/

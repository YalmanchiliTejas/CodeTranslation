#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

string s;
int d,n;

ll PD[100100][110][3];

ll pd(int i, int r, int up){
	if(i == n){
		return r != 0 ? 0 : 1;
	}
	int dig = s[i]-'0', lim = 10;
	ll &ans=PD[i][r][up];
	if(ans!=-1){
		return ans;
	}
	ans = 0;
	if(up){
		lim = dig;
		ans+=pd(i+1,(r+dig)%d, 1);
		ans%=MOD;
	}
	for(int j = 0; j < lim; j++){
		ans+=pd(i+1, (r+j)%d, 0);
		ans%=MOD;
	}
	return ans;
}

int main(){
	cin >> s;
	cin >> d;
	n = sz(s);
	memset(&PD, -1, sizeof PD);
	ll ans = pd(0, 0, 1);
	ans--;
	if(ans == -1){
		ans+=MOD;
	}
	cout << ans << endl;
	return 0;
}
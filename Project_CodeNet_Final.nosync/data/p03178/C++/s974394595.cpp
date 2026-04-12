#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(ll i = 0; i < n; i++)
#define F1(i,n) for(ll i = 1; i <= n; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = b-1; i >= a; i--)
#define FIN ios::sync_with_stdio(false);cin.tie(0);
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define all(v) v.begin(),v.end()
#define modulo(a,b) ((a%b)+b)%b
#define F first
#define S second
#define INF 1000000010
#define INFLL 1000000000000000000
#define eps 0.000000000001
#define mod 1000000007
template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//=======================//

const int maxn = 10010, maxd = 101;
char K[maxn];
vector<vector<ll>> dp;
int D;

/*
dp[sum][all] = Cantidad de maneras (hasta ahora) de elegir digitos tal que
su suma modulo D es sum. 'all' dice si vale elegir cualquier digito de 0 a 9 (esto pasa cuando
en algun paso anterior podia elegir digitos por ejemplo entre 0 y 5, y elegi un numero estrictamente menor
que 5. Si siempre vengo eligiendo el digito mas grande posible, entonces ahora no puedo elegir un numero
mayor al correspondiente en K).
*/

void sumar(ll& a, ll b) {
	a += b;
	if (a > mod) a-=mod;
}

int main () {
	//FIN
	string s; cin >> s;
	cin >> D;
	int size = 0;
	for(char c : s) {
		K[size++] = c - '0';
	}
	dp = vector<vector<ll>>(maxd, vll(2,0));
	F0(i,maxd) F0(j,2) dp[i][j] = 0;
	dp[0][0] = 1; // Despues de 0 pasos, puedo sumar 0 (de una sola manera).
	for (int i = 0; i < size; i++) {
		char actual = K[i];
		vector<vector<ll>> dp_new(maxd, vll(2,0));
		//El caso donde ya mire i digitos ya lo tengo en el vector dp. Itero por cada estado de dp y me muevo.
		for (int sum = 0; sum < D; sum++) {
			for (bool all : {false, true}) {
				for (int digit = 0; digit < 10; digit++) {
					if (!all && digit > actual) break;
					bool all_new = all || digit < actual;
					sumar(dp_new[(sum+digit)%D][all_new], dp[sum][all]);
				}
			}
		}
		dp = dp_new;
	}
	//La respuesta considera todos los numeros entre 0 y K, por lo que hay que restar 1 (El enunciado pide no contar 0).
	ll res = dp[0][true] + dp[0][false] - 1;
	res = modulo(res,mod);
	cout << res << "\n";




	return 0;
}









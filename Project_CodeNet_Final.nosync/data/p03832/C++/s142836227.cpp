#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=1050;
//ここまでテンプレ
#define rep(i,a,n) for(int i=a; i<n; i++)
#define repq(i,a,n) for(int i=a; i<=n; i++)
ll fact_mod(ll n, ll mod) {
    ll f = 1; repq(i,2,n) f = f * (i % MOD) % MOD;
    return f;
}
// 繰り返し二乗法 (再帰バージョン)
ll mod_pow(ll x, ll n, ll mod) {
    if(n == 0) return 1;
    ll res = mod_pow((x * x) % mod, n / 2 , mod);
    if(n & 1) res = (res * x) % mod;
    return res;
}
// 組み合わせ nCr を求める (modあり)
ll combination_mod(ll n, ll r, ll mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    ll a = 1;
    rep(i, 0, r) a = a * ((n-i) % mod) % mod;
    ll b = mod_pow(fact_mod(r, mod), mod-2, mod);
    return (a % mod) * (b % mod) % mod;
}
int N,A,B,C,D;
int main(){
	cin>>N>>A>>B>>C>>D;
	//%MOD下での階乗
	ll ex[SIZE]={1,0};
	for(int i=1;i<SIZE;i++){
		ex[i]=ex[i-1]*i%MOD;
	}
	//%MOD下での階乗の逆数
	ll inv[SIZE]={1,0};
	for(int i=1;i<SIZE;i++){
		inv[i]=mod_pow(i,MOD-2,MOD);
	}
	for(int i=1;i<SIZE;i++){
		inv[i]=inv[i-1]*inv[i]%MOD;
	}
	//モジュラ逆元
	ll gyaku[SIZE]={1,0};
	//コンビネーション
	ll comb[SIZE][SIZE]={};
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<=i;j++)
			comb[i][j]=ex[i]*inv[i-j]%MOD*inv[j]%MOD;
	for(int i=1;i<SIZE;i++)
		gyaku[i]=mod_pow(i,MOD-2,MOD);
	//DP[j][i]=j人をi人以下のグループに分けるときの分け方
	ll DP[SIZE][SIZE]={};
	for(int i=0;i<=N;i++)
		DP[i][0]=1;
	for(int i=A;i<=B;i++){
		for(int j=0;j<=N;j++){
			//DP[i][j]が0のときは、無意味なので飛ばす
			if(DP[i][j]==0)
				continue;
			//k==0のとき、func()==1;
			//j==0のときは足さない（1なので）
			if(j!=0){
				DP[i+1][j]+=DP[i][j];
				DP[i+1][j]%=MOD;
			}
			//Fをつくる
			ll F=1;
			//(N-j)Ci*(N-j-i)Ci*...*(N-j-(C-1)i)Ci
			for(int k=0;k<C;k++){
				if(N-j-k*i>=0)
					F*=comb[N-j-k*i][i];
				F%=MOD;
				F*=gyaku[k+1];
				F%=MOD;
			}
			for(int k=1;k<=D;k++){
				//N以上に遷移する必要はない
				if(j+i*k>N)
					break;
				if(C<=k){
					DP[i+1][j+i*k]+=DP[i][j]*F%MOD;
					DP[i+1][j+i*k]%=MOD;
					F*=comb[N-j-k*i][i];
					F%=MOD;
					F*=gyaku[k+1];
					F%=MOD;
				}
			}
		}
	}
	cout<<DP[B+1][N]<<endl;
	return 0;
}
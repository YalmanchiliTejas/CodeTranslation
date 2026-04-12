//インクルード(アルファベット順)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<chrono>//実行時間計測
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm,accumulate
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//順序保持しないmap
#include<unordered_set>//順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列
#include<stdio.h>

using namespace std;
typedef long long ll;
//マクロ
//forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange
//略記
#define PB push_ABck //挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PI 3.14159265358979323846264338327950L


#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define int long long
#define Graph vector<vector<int> >
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int> >
#define VPII vector<pair<int,int> >

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

long long powmod(long long x, long long n) {
	long long ret = 1;
	while (n > 0) {
		if (n & 1) ret = ret * x % MOD;  // n の最下位bitが1ならば(nが奇数ならば) x^(2^i) をかける
		x = x * x % MOD;
		n >>= 1;  // n を1bit 左にずらす
	}
	return ret;
}

int ctoi(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return 0;
	}
}


int gcd(int a, int b)
{
	if (a % b == 0) {
		return (b);
	}

	else
	{
		return (gcd(b, a % b));
	}
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

bool isPrime(int x) {
	int i;
	if (x < 2)return 0;
	else if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (i = 3; i * i <= x; i += 2) if (x % i == 0) return 0;
	return 1;
}

map< int, int > prime_factor(int n) {
	map< int, int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1; //素数だった時の
	return ret;
}



long long nCr(long long n, long long r) {
	long long x = 1, y = 1;

	for (int
	        i = 0; i < r; i++) {
		x = x * (n - i) % MOD ;
		y = y * (i + 1) % MOD;
	}

	return x * powmod(y, MOD - 2) % MOD;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ここにグローバル変数宣言

int dhh[4] = {1, 0, -1, 0};
int dww[4] = {0, 1, 0, -1};//BFS関連



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ここに関数宣言



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
signed main() {
	//入力の高速化
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int N;
	cin >> N;
	VI A(N);
	int sum = 0;
	REP(i, N) {cin >> A[i]; sum += A[i]%MOD;}

	sum%=MOD;

	int ans = 0;

	REP(i, N - 1) {
		sum -= A[i];
		ans += ( (A[i] % MOD) * ((sum) % MOD)) % MOD;
		ans %= MOD;
	}

	if (ans < 0)ans += MOD;

	cout << ans % MOD << endl;



}




















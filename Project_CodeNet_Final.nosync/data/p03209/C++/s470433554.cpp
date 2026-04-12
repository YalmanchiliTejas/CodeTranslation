#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<ll> height;
vector<ll> patty;

ll rec(ll N, ll X)
{

	//レベルLハンバーガーを
	//パン|レベル(N - 1)|パティ|レベル(N - 1)|パン
	//に分けて考える。

	//メモで計算再利用
	if (X >= height[N]) return patty[N];

	//0枚以下->食べられない
	//1枚　　->パン
	if (X <= 1) return 0;
	X--;

	ll ret = 0;

	//下半分のレベル(N - 1)
	ret += rec(N - 1, X);

	X -= height[N - 1];

	//真ん中のパティ
	if (X > 0)
	{
		ret++;
		X--;
	}

	//上半分のレベル(N - 1)
	ret += rec(N - 1, X);

	return ret;
}

int main()
{	
	ll N, X;
	cin >> N >> X;

	//各レベルごとに枚数を計算
	height.resize(N + 1);
	height[0] = 1;

	rep(i, N)
	{
		height[i + 1] = 2 * height[i] + 3;
	}

	patty.resize(N + 1);
	patty[0] = 1;

	rep(i, N)
	{
		patty[i + 1] = 2 * patty[i] + 1;
	}

	cout << rec(N, X) << endl;
	
	return 0;
}
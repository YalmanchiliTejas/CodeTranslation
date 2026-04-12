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

int main()
{	
	int N;
	cin >> N;

	vector<ll> A(N);
	rep(i, N) cin >> A[i];

	sort(all(A));

	//例えばa > b > c > d > eとして
	//b d a e c
	//と並べると
	//答え= (b - d) + (a - d) + (a - e) + (c - e)
	//　　= 2a + b + c - 2d - 2e
	//となる。つまり大きい数字や小さい数字をほかの数字で挟んだほうが有利。
	//（端の数字は1回しか寄与しない）
	//あとは端から順番に
	//・（Aグループ）大きいほうは2倍して足す
	//・（Bグループ）小さいほうは2倍して引く
	//・（Cグループ）真ん中の2個（両端）は小さいほうを引く、大きいほうを足す
	//とすればよい。
	//Nが奇数の場合はAグループとBグループの個数が異なるため（Cグループは2個固定）
	//Aグループが多い場合、Bグループが多い場合でそれぞれ計算して最大を採用。
	if (N % 2 == 0)
	{
		ll ans = 0;

		rep(i, N / 2 - 1) ans += -2 * A[i];
		ans += -A[N / 2 - 1];
		ans += A[N / 2];
		repl(i, N / 2 + 1, N) ans += 2 * A[i];

		cout << ans << endl;
	}
	else
	{
		//Aが多いパターン
		ll ans1 = 0;

		rep(i, N / 2 - 1) ans1 += -2 * A[i];
		ans1 += -A[N / 2 - 1];
		ans1 += -A[N / 2];
		repl(i, N / 2 + 1, N) ans1 += 2 * A[i];

		//Bが多いパターン
		ll ans2 = 0;

		rep(i, N / 2) ans2 += -2 * A[i];
		ans2 += A[N / 2];
		ans2 += A[N / 2 + 1];
		repl(i, N / 2 + 2, N) ans2 += 2 * A[i];

		cout << max(ans1, ans2) << endl;
	}

	return 0;
}
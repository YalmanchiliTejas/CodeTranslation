/*
	ID: Loxilante
	Time: 2020/08/
	Prog: 
	Lang: cpp
*/
#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#endif
#include <bits/extc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define hrp(i, l, r) for(int i = l; i <= r; i++)
#define rev(i, r, l) for(int i = r; i >= l; i--)
#define ms(n, t) memset(n, t, sizeof(n))
#define pb push_back
#define int ll
#ifndef JOEON
#define D(...) 97
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename tn = int> inline tn next(void) { tn k; cin>>k; return k; }
const int U = 3e5;
const int mod = 1000000007;
int sum[U], w[U];
inline int SUM(int i, int j)
{
	return sum[j] - sum[i-1];
}
signed main(void)
{
	clock_t Begin = clock();

	#ifdef JOEON
//		freopen("C:\\Users\\Joeon\\Desktop\\IN.txt", "r", stdin);
//		freopen("C:\\Users\\Joeon\\Desktop\\OUT.txt", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n = next(), ans = 0;
	hrp(i, 1, n) cin>>w[i];
	
	clock_t InputFinished = clock();
	
	hrp(i, 1, n) sum[i] = (sum[i-1]+w[i])%mod; // 1 2 3 4 5: 1 3 6 10 15

	hrp(i, 1, n-1)
		ans = (ans+w[i]*SUM(i+1, n))%mod;

	cout<<(ans+mod)%mod<<endl;
	
	clock_t End = clock();
	
	D((double)(End-Begin)/CLOCKS_PER_SEC);
	D((double)(End-InputFinished)/CLOCKS_PER_SEC);
	
	return 0;
}
/*

 */
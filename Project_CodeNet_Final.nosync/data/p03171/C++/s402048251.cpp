#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define eof !cin.eof()
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define ull unsigned long long
#define ll long long
#define ld long double
#define sz(a) a.size()
#define all(s) s.begin(), s.end()
#define rall(s, n) s, s + n
#define x first
#define y second
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define ii pair <int, int>
#define iii pair <int, ii>
#define vi vector <int>
#define vit vector <int> :: iterator
#define vlt vector <ll> :: iterator
#define vl vector <ll> 
#define vii vector <ii>
#define viii vector <iii>
#define vd vector <double>
#define vull vector <ull>
#define vc vector <char>
#define vs vector <string>
#define vb vector <bool>
#define vvi vector <vector <int>>
#define vvl vector <vector <ll>>
#define EPS 1e-10
#define INF 1000000000
#define mod 1000000007
#define reset(a, nilai) memset(a, nilai, sizeof(a))
#define minof min_element
#define maxof max_element
using namespace std;

const int nax = 3e3 + 5;
int n;
ll dp[nax][nax];
int main () {
	IOS;
	
	scanf("%d", &n);
	vi a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int L = n - 1; L >= 0; L--) {
		for (int R = L; R < n; R++) {
			if (L == R) {
				dp[L][R] = a[L];
			} else {
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			}
		}
	}
	printf("%lld\n", dp[0][n - 1]);
	return 0;
}
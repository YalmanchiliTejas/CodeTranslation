/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef unsigned long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)
  
// states - position, count, tight 
const int M = 105;
ll dp[M][M][2];
int K;

ll countInRangeUtil(int pos, int cnt, int tight, vector<int> num) {
	if (pos == num.size()) {
		if (cnt <= K)
			return 1;
		return 0;
	}
	if (dp[pos][cnt][tight] != -1)
		return dp[pos][cnt][tight];
	ll ans = 0;
	ll limit = (tight ? 9 : num[pos]);
	for (int dig = 0; dig <= limit; dig++) { 
		int currCnt = cnt;
		if (dig != 0)
			currCnt++;
		int currTight = tight;
		if (dig < num[pos])
			currTight = 1;
		ans += countInRangeUtil(pos + 1, currCnt, currTight, num);
	}
	return dp[pos][cnt][tight] = ans; 
}

ll countInRange(string &s) { 
	vector<int> num; 
	for (auto &it : s) { 
		num.push_back(it - '0'); 
	}
	memset(dp, -1, sizeof(dp)); 
	return countInRangeUtil(0, 0, 0, num); 
} 

int main() {
	string N;
	cin >> N >> K;
	string tmp = "0";
	int ans = countInRange(N) - countInRange(tmp);
	--K;
	if (K > 0) {
		ans -= (countInRange(N) - countInRange(tmp));
		--K;
	}
	printf("%d\n", ans);
	return 0;
}
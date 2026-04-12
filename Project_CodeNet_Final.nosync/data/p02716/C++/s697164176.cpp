#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
 
#ifndef ONLINE_JUDGE
	#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#else
	#define DEBUG(x) do {} while(0);
#endif
 
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define PER(i, N) for(int (i) = (N)-1; (i) >= 0; (i)--)
#define REP(i, N) for(int (i) = 0; (i) < (int)(N); (i)++)
 
using namespace std;
typedef long long ll;
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
const int MOD = 1000000007;

ll dp[222222][2];
ll sumEven[222222];
ll sumOdd[222222];

ll solve(const vector<int>& A, int last) {
	if(last == 0) {
		return 0;
	}
	return max(
		A[last]+solve(A, last-2),
		max(dp[last][0], dp[last][1])
	);
}

void solve(istream& cin, ostream& cout) {
	int n;
	cin >>n;
	vector<int> A(n);
	cin >> A;
	REP(i, n) {
		sumEven[i+1] = sumEven[i];
		sumOdd[i+1] = sumOdd[i];
		if(i % 2 == 0) sumEven[i+1] += A[i];
		if(i % 2 == 1) sumOdd[i+1] += A[i];
	}
//	dp[0][0] = -(1LL<<62);
	REP(i, n/2) {
		dp[2*i+2][0] = dp[2*i][0]+A[2*i];
		dp[2*i+2][1] = max(dp[2*i][0]+A[2*i+1], dp[2*i][1]+A[2*i+1]);
	//	cout << 2*i+2 << " " << dp[2*i+2][0]  << " . " << dp[2*i+2][1]<<endl;
	}
	if(n % 2 == 0) {
		cout << max(dp[n][0], dp[n][1]) <<endl;
	} else { 
		cout << solve(A, n-1) << endl;
	}

	/*else {
		ll ans = 0;
		REP(i, n) {
			ll cans = 0;
			if(i % 2 == 0) {
				cans = max(sumEven[i], sumOdd[i]);
				ll restEven = sumEven[n]-sumEven[i+1];
				ll restOdd = sumOdd[n]-sumOdd[i+1];
				cans += max(restEven, restOdd);
			} else {
				ll restEven = sumEven[n]-sumEven[i+1];
				ll cand1 = restEven+sumOdd[i];
				ll restOdd = sumOdd[n]-sumOdd[i+1];
				ll cand2 = restOdd+sumEven[i];
				cans = max(cand1, cand2);
			}
			cout << cans<<endl;

			ans = max(ans, cans);
		}
		cout <<ans<<endl;
	}*/
	/*
	
	
	REP(i, n) {
		ll prevDp[3][2];
		REP(j, 3) REP(k, 2) {
			prevDp[j][k] = dp[j][k];
			cout << "dp[" << j << "," << k <<"]=" <<prevDp[j][k]<<endl;
		}
		dp[0][0] = prevDp[0][1];
		dp[0][1] = prevDp[0][0]+A[i];
		if(n % 2 == 1) {
			dp[2][0] = max(prevDp[0][0], prevDp[0][1]);
			
			dp[1][0] = max(prevDp[2][0], prevDp[1][1]);
			dp[1][1] = max(prevDp[2][0]+A[i], prevDp[1][0]+A[i]);
		}
	}
	ll ans = -(1LL<<62);
	REP(j, 2) REP(k, 2) ans = max(ans, dp[j][k]);
	cout << ans << endl;*/
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	solve(cin, cout);
	/*
	{
		istringstream instr("2\n2\n14");
		solve(instr, cout);
	}
 */
	return 0;
}

#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define MAP map<int,int>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e17;

int gcd(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (a < b) swap(a, b);
	while (b != 0) {
		a = a%b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b) {
	if (a == 0 || b == 0) return 0;
	return a / gcd(a, b)*b;
}

vector<bool> Eratosthenes(int N) {
	vector<bool> Eratosthenes(N + 1,true);
	Eratosthenes[0] = false;
	if (N == 0) return Eratosthenes;
	Eratosthenes[1] = false;
	for (int i = 1; i*i <= N; i++) if (Eratosthenes[i]) for (int j = 2 * i; j <= N; j += i) Eratosthenes[j] = false;
	return Eratosthenes;
}

bool pcheck(int N) {
	if (N == 0 || N == 1) return false;
	for (int i = 2; i*i <= N; i++) if (N % i == 0) return false;
	return true;
}

//vector including modulus of N!
vector<ll> factorial(ll N, ll quotient) {
	vector<ll> factorial(N + 1, 1);
	for (ll i = 1; i <= N; i++) {
		factorial[i] *=factorial[i - 1]*i;
		factorial[i] %= quotient;
	}
	return factorial;
}

//repeat square method y = x^n mod quotient 
ll rsm(ll x,ll n,ll quotient){
	ll y = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			y *= x;
			y %= quotient;
		}
		x *= x;
		x %= quotient;
		n >>= 1; 
	}
	return y;
}

//modulus of nCk - combination mod 
ll nCk(ll n, ll k, ll quotient) {
	vector<ll> f = factorial(n, quotient);//erase this line when you use!
	ll nCk = (f[n] % quotient);
	nCk *= rsm(f[k], quotient - 2, quotient);
	nCk %= quotient;
	nCk *= rsm(f[n - k], quotient - 2, quotient);
	return (nCk % quotient);
}

//union-find---------------------------------------------------
int node[10];

int root(int n) {
	if (node[n] == n) return n;
	else return node[n] = root(node[n]);
}

void unite(int n, int m) {
	if (n > m) swap(n, m);
	n = root(n);
	m = root(m);
	if (n == m) return;
	else node[m] = n;
}
//-------------------------------------------------------------

void ANS(bool flag){
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Ans(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void ans(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int main() {
	int N;	cin >> N;
	string S; cin >> S;

	VI T(N,0);
	if(S[1] == 'o'){
		T[0]++; T[1]++; T[2]++;
		for(int i = 2; i < N; i++){
			if (S[i - 1] == 'o' && T[i - 1] == 1 ) T[i] =  T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1 ) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] =  T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] == T[1]) || (S[0] == 'x' && T[N - 1] != T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0]))) 
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0]))) ){
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'o') {
		T[0]--; T[1]++; T[2]--;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] != T[1]) || (S[0] == 'x' && T[N - 1] == T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'o') {
		T[0]++; T[1]--; T[2]--;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1 ) T[i] =  T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1 ) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] =  T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] == T[1]) || (S[0] == 'x' && T[N - 1] != T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'o') {
		T[0]--; T[1]--; T[2]++;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] != T[1]) || (S[0] == 'x' && T[N - 1] == T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;




	if (S[1] == 'x') {
		T[0]++; T[1]++; T[2]--;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] == T[1]) || (S[0] == 'x' && T[N - 1] != T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'x') {
		T[0]--; T[1]++; T[2]++;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] != T[1]) || (S[0] == 'x' && T[N - 1] == T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'x') {
		T[0]++; T[1]--; T[2]++;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] == T[1]) || (S[0] == 'x' && T[N - 1] != T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	if (S[1] == 'x') {
		T[0]--; T[1]--; T[2]--;
		for (int i = 2; i < N; i++) {
			if (S[i - 1] == 'o' && T[i - 1] == 1) T[i] = T[i - 2];
			if (S[i - 1] == 'o' && T[i - 1] == -1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == 1) T[i] = -T[i - 2];
			if (S[i - 1] == 'x' && T[i - 1] == -1) T[i] = T[i - 2];
		}
		if ((S[0] == 'o' && T[N - 1] != T[1]) || (S[0] == 'x' && T[N - 1] == T[1])) {
			if ((S[N - 1] == 'o' && ((T[N - 1] == 1 && T[N - 2] == T[0]) || (T[N - 1] == -1 && T[N - 2] != T[0])))
				|| (S[N - 1] == 'x' && ((T[N - 1] == 1 && T[N - 2] != T[0]) || (T[N - 1] == -1 && T[N - 2] == T[0])))) {
				string S_;
				REP(i, N) {
					if (T[i] == 1) S_ += "S";
					if (T[i] == -1) S_ += "W";
				}
				cout << S_ << endl;
				return 0;
			}
		}
	}
	REP(i, N) T[i] = 0;

	cout << -1 << endl;
	
	return 0;
}

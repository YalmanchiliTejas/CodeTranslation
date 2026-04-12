
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 1000000007;
        
//bool operator< (pint a, pint b) {
	//return a.second < b.second;

//}



ll gcd(ll a, ll b) {

	if (b == 0)
		return a;

	return gcd(b, a % b);


}

ll max(ll a, ll b) {
	if (a < b) {
		return b;
	}
	else
		return a;

}

ll min(ll a, ll b) {
	if (a < b)
		return a;

	return b;
}




pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pint> list;










void floyd(int N, ll** d) {

	rep(k, N+1){
		rep(i, N+1) {
			if (d[i+1][k+1] == inf) continue;
			rep(j, N+1) {
				if (d[j+1][k+1] == inf) continue;

				d[i+1][j+1] = min(d[i+1][j+1], d[i+1][k+1] + d[j+1][k+1]);

			}

		}
	}




}


ull modpow(ull a, ull b) {
	ll retval = 0;

	if (b == 0) { return 1; }

	else if (b % 2 == 0) {
		retval = modpow(a, b / 2) % mod;
		return (retval * retval) % mod;
	}

	else {
		
		return ((a % mod) * modpow(a, b - 1)) % mod;
	}
}

ll pow(ll a, ll b){
	ll ret;
	if (b == 0) return 1;
	else if (b % 2 == 0) { ret = pow(a, b / 2); return ret * ret; }
	else if (b % 2 == 1) { return a * pow(a, b - 1); }


}


int bit(ll a, ll n) {
	if (a & pow(2, n-1) != 0) {
		return 1;
	}
	else {
		return 0;
	}
	
	
}


ull modkaijou(ull a) {

	if (a == 1 || a == 0) { return 1; }

	ll retval = 1;

	for (ull i = a; i >= 1; i--) {
		retval = (retval * (i % mod)) % mod;
	}

	return retval % mod;
}

ull modcomb(ull a, ull b) {

	if (a == 0 || b == 0) return 1;

	return (((modkaijou(a) * modpow(modkaijou(a-b), mod - 2)) % mod) * modpow(modkaijou(b), mod - 2)) % mod;
}


class DisjointSet {
public:
	vector<int> p, rank, num;


	DisjointSet() {}

	DisjointSet(int size) {
		rank.resize(size, 0);
		p.resize(size, 0);
		num.resize(size, 0);
		rep(i, size) { p[i] = i; rank[i] = 0; num[i] = 1; }
	}

	bool same(int x, int y) {

		return findSet(x) == findSet(y);

	}

	void unite(int x, int y) {
		if(!same(x, y))
		link(findSet(x), findSet(y));
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {

			p[y] = x;
			num[x] += num[y];

		}

		else {
			p[x] = y;
			num[y] += num[x];
			if (rank[x] == rank[y]) {

				rank[y]++;
			}

		}


	}


	ll NumberOfElements(int x) {

		return num[findSet(x)];

	}


	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);
			num[x] = 1;
		}

		return p[x];
	}



};


bool compare_b(pint a, pint b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		return a.second < b.second;
	}

	else {
		return false;
	}

}


int ketasuu(int a) {

	int ret = 1;
	int val = a;
	while (val / 10 != 0) {

		ret += 1;
		val /= 10;
	}
	return ret;
}

typedef struct trio {
	ll a, b, y;
}ti;


string to_binary(ll a) {
	ll val = a;
	string retval = "";

	retval = to_string(val % 2);
	while (val / 2 != 0) {
		val /= 2;
		retval = (to_string(val % 2)) + retval;

	}

	
	


	return retval;
}

int ctoi(char a) {

	return a - '0';
}







string S;
string ans;

vector<string> batu_pat = { "SWS", "WWW", "SSW", "WSS" };
vector<string> maru_pat = { "SSS", "WSW", "WWS", "SWW" };

bool check(string s, string ans, int N) {
	bool retval;
	int rindex = (N + 1) % s.size();
	int lindex = (N - 1 >= 0) ? N - 1 : s.size() - 1;
	int index = N % s.size();

	if (s[index] == 'o') {
		if (ans[index] == 'S') {
			retval = (ans[lindex] == ans[rindex]);
			
		}

		else {
			retval = (ans[lindex] != ans[rindex]);
		}

	}

	else if (s[index] == 'x') {
		if (ans[index] == 'S') {
			retval = (ans[lindex] != ans[rindex]);
		}

		else {
			retval = (ans[lindex] == ans[rindex]);
		}

		 

	}

	return retval;

}



int main() {
	ll N;
	vector<string> pat;
	cin >> N;

	cin >> S;

	if (S[1] == 'o') {
		pat = maru_pat;

	}
	else
		pat = batu_pat;
	

	for (int j = 0; j < pat.size(); j++) {
		ans = "";
		ans = ans + pat[j];
		for (int i = 3; i < S.size(); i++) {
			if (S[i - 1] == 'o' && ans[i - 1] == 'S') {

				ans = ans + ans[i - 2];
			}
			else if (S[i - 1] == 'o' && ans[i - 1] == 'W') {

				ans = ans + ((ans[i - 2] == 'S') ? "W" : "S");
			}

			else if (S[i - 1] == 'x' && ans[i - 1] == 'S') {

				ans = ans + ((ans[i - 2] == 'S') ? "W" : "S");
			}

			else {
				ans = ans + ans[i - 2];
			}

		}


		if ((check(S, ans, S.size() - 1) && check(S, ans, 0))) {
			cout << ans << endl;
			return 0;

		}


	}

	cout << -1 << endl;
	return 0;
}
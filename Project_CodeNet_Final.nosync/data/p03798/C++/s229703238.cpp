#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#define REP(i, N) for(int i = 0; i < N; ++i)
#define REEP(i, N) for(int i = N - 1; i >= 0; --i)
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,m,n) for(int i = m; i < n; ++i)
#define RFOR(i,m,n) for(int i = n - 1; i >= m; --i)
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a << endl
#define COUT2(a, b) cout << a << " " << b << endl
#define COUT3(a, b, c) cout << a << " " << b << " " << c << endl
#define pb push_back
#define PB push_back
#define VINT(v, n) vector<int> v(n); REP(i, n) { v[i] = 0 }
#define VINT2(v, n, m) vector<vector<int> > v(n, vector<int>(m)); REP(i, n) { REP(j, m) { v[i][j] = 0 } }
#define VCHAR(v, n) vector<char>v(n)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define CEIL(c, a, b) if(a % b == 0) { c = a / b;} else { c = a / b + 1;}
#define sp(n) setprecision(n)
#define INF 100000000

using namespace std;
typedef pair<int, int> P;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

int main() {
	int N;
	CIN(N);
	bool tf = false;
	vector<char> s(N);
	vector<bool> v(N, false);
	REP(i, N) {
		CIN(s[i]);
	}
	if(s[0] == 'o') {
		v[0] = true;		// o羊
		v[N - 1] = true;	// 羊羊
		v[1] = true;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = true;		// o羊
		v[N - 1] = false;	// 狼狼
		v[1] = false;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = false;		// o狼
		v[N - 1] = false;	// 狼羊
		v[1] = true;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = false;		// o狼
		v[N - 1] = true;	// 羊狼
		v[1] = false;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}
	}


	else if(s[0] == 'x') {
		v[0] = true;		// x羊
		v[N - 1] = true;	// 羊狼
		v[1] = false;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = true;		// x羊
		v[N - 1] = false;	// 狼羊
		v[1] = true;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = false;		// x狼
		v[N - 1] = false;	// 狼狼
		v[1] = false;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}

		v[0] = false;		// x狼
		v[N - 1] = true;	// 羊羊
		v[1] = true;
		for(int i = 1; i < N; ++i) {
			if(i == N - 1 && tf) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[0] == v[i - 1]);
					else tf = (v[0] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[0] == !v[i - 1]);
					else tf = (v[0] == v[i - 1]);
				}
			}
			if(i == N - 2) {
				if(s[i] == 'o') {
					if(v[i]) tf = (v[i + 1] == v[i - 1]);
					else tf = (v[i + 1] == !v[i - 1]);
				} else if(s[i] == 'x') {
					if(v[i]) tf = (v[i + 1] == !v[i - 1]);
					else tf = (v[i + 1] == v[i - 1]);
				}
			} else {
				if(s[i] == 'o') {
					if(v[i]) v[i + 1] = v[i - 1];
					else v[i + 1] = !v[i - 1];
				} else if(s[i] == 'x') {
					if(v[i]) v[i + 1] = !v[i - 1];
					else v[i + 1] = v[i - 1];
				}
			}
		}
		if(tf) {
			REP(i, N) {
				if(v[i] == true) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}
	}

	if(!tf) {
		COUT(-1);
	}


}


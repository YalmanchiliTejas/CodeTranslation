#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void)
{	
	int h, w;
	cin >> h >> w;
	vector<vector<char>>a(h, vector<char>(w));
	vector<vector<int>>b(h, vector <int> (w,0));
	vector<vector<int>>c(h, vector <int>(w, 0));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == '#') {
				rep(k, h) {
					b[k][j]++;
				}
				rep(k, w) {
					c[i][k]++;
				}
			}
		}
	}

	rep(i, h) {
		bool println = false;
		rep(j, w) {
			if (b[i][j] >= 1 && c[i][j] >= 1) {
				cout << a[i][j];
				println = true;
				if(j==w-1)cout << "" << endl;
			}
			else if (j == w - 1 && println)cout << "" << endl;
		}
	}
}
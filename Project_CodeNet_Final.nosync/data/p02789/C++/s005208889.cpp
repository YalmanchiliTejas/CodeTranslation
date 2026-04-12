#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >

int N, M;

int main() {

	cin >> N >> M;
	if (M / N) cout << "Yes" << endl;
	else cout << "No" << endl;

}


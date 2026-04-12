#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const int INF = 0x3fffffff;


int main(){
	int H, W;
	char A[10][10];

	cin >> H >> W;
	rep(i,H) rep(j,W) cin >> A[i][j];
	
	int dp[10][10]={};
	dp[0][0] = 1;
	rep(i,H) rep(j,W) if( A[i][j] == '#' ){
		dp[i+1][j] += dp[i][j];
		dp[i][j+1] += dp[i][j];
	}
	bool ans = true;
	rep(i,H) rep(j,W) if( A[i][j] == '#' ){
		if( dp[i][j] != 1 ) ans = false;
	}

	rep(i,10) rep(j,10) dp[i][j] = 0;
	dp[H][W] = 1;
	rrep(i,H) rrep(j,W) if( A[i][j] == '#' ){
		dp[i+1][j] += dp[i+1][j+1];
		dp[i][j+1] += dp[i+1][j+1];
	}
	rep(i,H) rep(j,W) if( A[i][j] == '#' ){
		if( dp[i+1][j+1] != 1 ) ans = false;
	}

	cout << (ans?"Possible":"Impossible") << endl;

	return 0;
}

#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int N; cin >> N;
	int X[N];
	int Y[N];
	rep(i, N) {
		cin >> X[i];
		Y[i] = X[i];
	}
	sort(Y, Y + N);
	int medium0 = N / 2 - 1;
	int medium1 = medium0 + 1;
	rep(i, N) {
		if (X[i] <= Y[medium0]) cout << Y[medium1] << endl;
		else cout << Y[medium0] << endl;
	}



			

    return 0;
}

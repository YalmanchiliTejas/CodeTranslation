#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	int N;
	cin >> N;
	vector<ll> X(N);
	vector<pll> Y(N), Z(N);
	REP(i, N) cin >> X[i];
	REP(i, N){
		Y[i] = make_pair(X[i], (ll)i);
	}
	sort(Y.begin(), Y.end());
	REP(i, N){
		Z[i] = make_pair(Y[i].second, (ll)i);
	}
	sort(Z.begin(), Z.end());
	/*
	REP(i, N){
		cout << Y[i].first << " " << Y[i].second << endl;
	}
	cout << endl;
	REP(i, N){
		cout << Z[i].first << " " << Z[i].second << endl;
	}
	cout << endl;
	*/
	REP(i, N){
		cout << (Z[i].second < N/2 ? Y[N/2].first : Y[(N-1)/2].first ) << endl;
	}

    return 0;
}
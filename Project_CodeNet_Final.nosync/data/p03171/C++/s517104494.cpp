#include <bits/stdc++.h>
#define P 1000000007
#define ll long long
#define ld long double
#define N (1<<17)
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n, h[3030];
ll d[3030][3030], s;

ll dp(int a, int b, bool t){
	if(a>b) return 0;
	if(d[a][b]) return d[a][b];

	if(t){
		d[a][b] = max(dp(a+1, b, 0)+h[a], dp(a, b-1, 0)+h[b]);
	} else {
		d[a][b] = min(dp(a+1, b, 1), dp(a, b-1, 1));
	}

	return d[a][b];

}

int main(){

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> h[i];
		s += h[i];
	}

	ll x = dp(0, n-1, 1);

	cout << 2*x-s << endl;

	return 0;

}

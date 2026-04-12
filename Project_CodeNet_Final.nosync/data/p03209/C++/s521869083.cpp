#include "bits/stdc++.h"

using namespace std;

//typedef pair<int, int> P;
#define int long long
#define ll long long
#define mod 1000000007
#define INF (1LL<<60)



int powint(double a, double b){
	return (int)(pow(a, b) + 0.1);
}

// レベルnで、下からxまでのPの枚数
int P(int n, int x){
	if (n == 0){
		if (x == 0) return 0;
		else return 1;
	}
	if (x == 1)
		return 0;
	if (x <= 4 * powint(2.0, n-1) - 3 + 1)
		return P(n - 1, x - 1);
	else if (x == 4 * powint(2.0, n - 1) - 3 + 2)
		return P(n - 1, x - 1)+1;
	else
		return P(n - 1, x - (4 * powint(2.0, n - 1) - 3 + 2)) + (2 * powint(2.0, n - 1) - 1) + 1;
}

signed main(){

	int N, X;
	cin >> N >> X;

	cout << P(N, X) << endl;

	return 0;
}

#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

signed main() {
	double r1, r2; cin >> r1 >> r2;
	printf("%.10lf\n", 1. / (1. / r1 + 1. / r2));
}
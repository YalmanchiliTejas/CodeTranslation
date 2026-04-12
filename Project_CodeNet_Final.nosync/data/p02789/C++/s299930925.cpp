#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define str string
#define ALL(a)  (a).begin(),(a).end()
#define P pair<ll,ll>

using Graph = vector<vector<int>>;

const int dy[] = { 0, 0, 1, -1 }, dx[] = { 1, -1, 0, 0 };
ll INFL = 1ll << 60, INF = 1 << 30, mod = 1e9 + 7, Min = INFL, Max = -1;
ll a, b, c ,n, sum, A[500010], B[500000],rui[500000],  dp[5000];
str S,T;bool check = true;	vector<ll> v;



int main() {
	//Code Line
cin >>a >> b ;

if(a == b)cout << "Yes" << endl;
else cout << "No" << endl;



	return 0;
}

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<functional>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e10;
const ll MOD = 1e9 + 7;



int main(){
	ll N;
	vll X, Y;
	cin >> N;
	ll i, j;
	for (i = 0; i < N; i++){
		ll x;
		cin >> x;
		X.push_back(x);
		Y.push_back(x);
	}
	
	sort(Y.begin(), Y.end());

	ll d, u;
	d = Y[N / 2 - 1];
	u = Y[N / 2];

	for (i = 0; i < N; i++){
		if (X[i] < u){
			cout << u << endl;
		}
		else{
			cout << d << endl;
		}
	}
	return 0;
}

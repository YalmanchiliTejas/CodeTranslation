#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define cost first
#define from second.first
#define to second.second
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

int main(void){
	int r,g,b;
	cin >> r >> g >> b;
	cout << (((g*10+b)%4)?"NO":"YES") << endl;
	return 0;
}
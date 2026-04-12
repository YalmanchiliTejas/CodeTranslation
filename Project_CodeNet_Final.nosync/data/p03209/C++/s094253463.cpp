#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<stack>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#define rep(a,b) for(int a=0;a<b;++a)
#define REP(a,b,c,d) for(int a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_i = pair<int, int>;
vector<ll> a, p;
ll f(ll n, ll x) {
	if (n == 0) {
		if (x <= 0)return 0;
		else return 1;
	}
	else if (x <= 1 + a[n - 1]) {
		return f(n - 1, x - 1);
	}
	else {
		return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
	}
}
int main() {
	ll N, X; cin >> N >> X;
	a.push_back(1);
	p.push_back(1);
	for (int i = 0; i < N; ++i) {
		a.push_back(a[i] * 2 + 3);
		p.push_back(p[i] * 2 + 1);
	}
	cout << f(N, X) << endl;
	cin >> N;
}
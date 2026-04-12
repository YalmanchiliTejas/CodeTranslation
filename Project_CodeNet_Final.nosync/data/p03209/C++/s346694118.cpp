#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long v[55];
typedef pair<long long, long long> P;
map<P, long long> m;

long long f(long long a, long long b){
	if(a == 0) return b == 0 ? 0 : 1;
	if(b == 0) return 0;
	if(m.find(P(a, b)) != m.end())
		return m[P(a, b)];
	long long res = 0;
	if(b >= v[a-1] + 2){
		++res;
		res += f(a-1, min(b-v[a-1]-2, v[a-1]));
	}
	res += f(a-1, min(b-1, v[a-1]));
//	cout << a << " " << b << " " << res << "\n";
	m[P(a, b)] = res;
	return res;
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> x;
	v[0] = 1;
	for(int i=1; i<=n; ++i)
		v[i] = 2*v[i-1] + 3;
	cout << f(n, x) << "\n";
}
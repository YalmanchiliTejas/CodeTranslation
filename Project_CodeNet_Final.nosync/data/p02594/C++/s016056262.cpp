#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define rep(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define ffor(i,a,b) for(int i = a ; i <= b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
const int N = 1e6;
typedef pair <int, int> pi;
typedef std::vector<int> vi;
typedef std::vector<long long> VI;

/*bool isprime(int a) {
	if (a < 2) return false;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;  // 0(n) or 0(n^2) Tell me in the comment section
	}
	return true;
}*/



int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	fastIO
	int x;
	cin >> x;
	if (x >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;
}


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n); i >= 0; i--)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define REVSORT(c) SORT(c);REVERSE(c)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
const long long MOD = 1000000007;
typedef long long ll;

int main(){
	int j, k, l;
	cin >> j >> k >> l;
	cout << (((k * 10 + l) % 4 == 0) ? "YES" : "NO") << endl;
}
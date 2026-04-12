#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define allsort(v) sort(v.begin(),v.end())
const ll mod = 1e9 + 7;
const int inf = 1e9;

int main() {
	cin.sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	char a;
	int count = 0;
	rep(i, H) {
		rep(j, W) {
			cin >> a;
			if (a == '#')count++;
		}
	}
		cout << (count == H + W - 1 ? "Possible" : "Impossible") << endl;
	return 0;
}
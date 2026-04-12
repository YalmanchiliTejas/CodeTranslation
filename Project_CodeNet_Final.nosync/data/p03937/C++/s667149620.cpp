#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int num;
int H, W;

int main() {
	cin >> H >> W;
	rep(i, H) {
		string s;
		cin >> s;
		rep(j, W) num += (s[j] == '#');
	}
	puts(num == H+W-1 ? "Possible" : "Impossible");
	return 0;
}
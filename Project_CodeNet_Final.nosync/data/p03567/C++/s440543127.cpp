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

int main() {
	string s;
	cin >> s;
	bool f = 0;
	int n = s.size();
	rep(i, n-1) {
		if (s[i]=='A'&&s[i+1]=='C') {
			f = 1;
		}
	}
	puts(f?"Yes":"No");
	return 0;
}
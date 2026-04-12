#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sh cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define FILE freopen("test.in", "r", stdin);
#define vprint(v) for (int ii = 0; ii < v.size(); ii++){cout << v[ii] << " ";}
#define debugv(v) if (v.size() != 0) {cout << "[ "; for (int __ = 0; __ < (int)(v.size()) - 1; __++){cout << v[__] << ", ";} cout << v[(int)(v.size()) - 1] << " ]" << endl;} else {cout << "[]" << endl;}
#define debug cout << "-----------------------------------------------" << endl;
#define print1(a) cout << "{ " << a << " }" << endl;
#define print2(a, b) cout << "{ " << a << ", " << b << " }" << endl;
#define print3(a, b, c) cout << "{ " << a << ", " << b << ", " << c << " }" << endl;
#define print4(a, b, c, d) cout << "{ " << a << ", " << b << ", " << c << ", " << d << " }" << endl;
using namespace std;
#define int long long
const int INF = 1e9 + 228;
const int MAXN = 1e5 + 228;
string n;
int k;

void solve1() {
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		if (i != 0) {
			ans += 9;
			continue;
		}
		int f = n[0] - '0';
		ans += f;
		
	}
	cout << ans << endl;
}

void solve2() {
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		for (int j = i + 1; j < n.size(); j++) {
			if (i != 0) {
				ans += 81;
				continue;
			}
			int f = n[0] - '0';
			ans += (f - 1) * 9;
			bool flag = 1;
			for (int y = 1; y < j; y++) {
				if (n[y] != '0')
					flag = 0;
			}
			if (!flag) {
				ans += 9;
				continue;
			}
			int s = n[j] - '0';
			ans += s;
		}
	}
	cout << ans << endl;
}

void solve3() {
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		for (int j = i + 1; j < n.size(); j++) {
			for (int l = j + 1; l < n.size(); l++) {
				if (i != 0) {
					ans += 729;
					continue;
				}
				int f = n[0] - '0';
				f = max(f - 1, 0LL);
				ans += f * 81;
				if (n[0] == '0')
					continue;
				bool flag = 1;
				for (int y = 1; y < j; y++) {
					if (n[y] != '0')
						flag = 0;
				}
				if (!flag) {
					ans += 81;
					continue;
				}
				int s = n[j] - '0';
				s = max(s - 1, 0LL);
				ans += s * 9;
				if (n[j] == '0')
					continue;
				flag = 1;
				for (int y = j + 1; y < l; y++) {
					if (n[y] != '0')
						flag = 0;
				}
				if (!flag) {
					ans += 9;
					continue;
				}
				int t = n[l] - '0';
				ans += t;
			}
		}
	}
	cout << ans << endl;
}

string tos(int x) {
	string res = "";
	while (x > 0) {
		res += (x % 10);
		x /= 10;
	}
	return res;
}

signed main()
{
#ifdef LOCAL
    FILE;
#endif
    sh;
    cin >> n >> k;
    string kek = "";
    int id = -1;
    for (int i = 0; i < n.size(); i++) {
    	if (n[i] != '0' && id == -1) {
    		id = i;
    		break;
    	}
    }
    for (int i = id; i < n.size(); i++) {
    	kek += n[i];
    }
    n = kek;
    if (k == 1) {
    	solve1();
    } else if (k == 2) {
    	solve2();
    } else {
    	solve3();
    }

    return 0;
}

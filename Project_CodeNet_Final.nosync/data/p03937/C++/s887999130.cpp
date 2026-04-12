#include <bits/stdc++.h>//coded by Nurstan ^_^

#define ll long long
#define pb push_back

#define mp make_pair
#define lb lower_bound
#define ub upper_bound

#define all(x) x.begin(), x.end()
#define F first
#define S second

// fixed << setprecision
// next_permutation(a, a + n)
// set <int> :: iterator it = x.begin(); it != x.end(); it ++

using namespace std;

inline void boost(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main(){
	boost();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	char a[n][m];
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			cin >> a[i][j];
		}
	}
	if(a[0][0] != '#') {
		cout << "Impossible";
		return 0;
	}
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			if(a[i][j] == '#') {
				if(j + 1 < m && i + 1 < n && a[i + 1][j] == '#' && a[i][j + 1] == '#') {
					cout << "Impossible";
					exit(0);
				}
				bool t = 0;
				if(j - 1 >= 0 && a[i][j - 1] == '#') {
					t = 1;
				}
				if(i - 1 >= 0 && a[i - 1][j] == '#') {
					t = 1;
				}
				if(t == 0) {
					if(i != 0 || j != 0) {
						cout << "Impossible";
						return 0;
					}
				}
			}
		}
	}
	cout << "Possible";
	exit(0);
}


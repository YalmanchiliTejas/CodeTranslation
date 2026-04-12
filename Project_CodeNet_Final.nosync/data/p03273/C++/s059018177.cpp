#include <bits/stdc++.h>

using namespace std;

#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int h, w;
vector<int> r(105, 0);
vector<int> c(105, 0);
string s[105];

signed main()
{
	IOS;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				r[i] = 1;
				c[j] = 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (r[i]) {
			for (int j = 0; j < w; j++) {
				if (c[j]) {
					cout << s[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}


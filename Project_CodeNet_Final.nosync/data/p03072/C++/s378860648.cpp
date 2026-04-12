
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

int n;
int a[50];

int main()
{
	IOS;
	cin >> n;
	int e, m, c = 1;
	cin >> e;
	m = e;
	for (int i = 1; i < n; i++) {
		cin >> e; 
		if (m <= e) {
			m = e;
			c++;
		}
	}
	cout << c << endl;
	return 0;
}


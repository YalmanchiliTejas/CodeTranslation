#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct league {
	string name;
	int w, l, d, p;

	bool operator < (const league & rhs) const {
		return p > rhs.p;
	}
};

int main()
{
	int n;

	cin >> n;

	while (n > 0) {
		league sc[10];

		for (int i = 0; i < n; i++) {
			cin >> sc[i].name >> sc[i].w >> sc[i].l >> sc[i].d;
			sc[i].p = sc[i].w * 3 + sc[i].d;
		}

		sort(sc, sc + n);

		for (int i = 0; i < n; i++)
			cout << sc[i].name << "," << sc[i].p << endl;

		cin >> n;

		if (n > 0)
			cout << endl;
	}

	return 0;
}


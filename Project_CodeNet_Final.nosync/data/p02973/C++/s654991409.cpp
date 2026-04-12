#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

using vi = vector<int>;

int busBin(int ini, int fin, int buscado, vi const& ends) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		//if (ends[mitad] == buscado) return mitad;
		if (ends[mitad] >= buscado) return busBin(mitad + 1, fin, buscado, ends);
		else return busBin(ini, mitad, buscado, ends);
	}
}

bool res() {
	int n;
	cin >> n;
	if (!cin) return false;

	vi v(n);
	vector<bool> marcaje(n, true);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vi nmaxcol; nmaxcol.push_back(-1);

	for (int i = 0; i < n; ++i) {
		int posb = busBin(0, nmaxcol.size(), v[i], nmaxcol);
		if (posb == nmaxcol.size()) {
			nmaxcol.push_back(v[i]);
		}
		else {
			nmaxcol[posb] = v[i];
		}
	}

	cout << nmaxcol.size() << '\n';

	return true;
}

int main() {
	while (res()) {}
	return 0;
}
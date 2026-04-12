#include <iostream>
#include <cmath>

using namespace std;

unsigned int tanri(unsigned int moto, int tosi, int tesu, double nenri) {
	int risi = 0;
	for (int i = 0; i < tosi; i++) {
		risi += (double)moto * nenri;
		moto -= tesu;
	}
	//cout << moto+risi << endl;
	return moto+risi;
}

unsigned int fukuri(unsigned int moto, int tosi, int tesu, double nenri){
	for (int i = 0; i < tosi; i++) {
		moto += (double)moto * nenri;
		moto -= tesu;
	}
	//cout << moto << endl;
	return moto;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned int moto;
		int year;
		cin >> moto >> year;
		int m;
		cin >> m;
		int tf;
		double nritu;
		int tryo;
		unsigned int maxkane = 0;
		for (int j = 0; j < m; j++) {
			cin >> tf >> nritu >> tryo;
			if (tf == 0) {
				maxkane = max(maxkane, tanri(moto, year, tryo, nritu));
			} else {
				maxkane = max(maxkane, fukuri(moto, year, tryo, nritu));
			}
		}
		cout << maxkane << endl;
	}

	return 0;
}
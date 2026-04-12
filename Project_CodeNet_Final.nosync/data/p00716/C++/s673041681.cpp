#include<iostream>
using namespace std;

int main()
{
	int m, fund, year, n, type, charge, maxim;
	double rate;
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> fund >> year >> n;
		maxim = 0;
		for (int j = 0; j < n; j++) {
			cin >> type >> rate >> charge;
			int tmp = fund;
			if (type) {
				for (int k = 0; k < year; k++) {
					tmp += tmp * rate - charge;
				}
			} else {
				int tmp2 = 0;
				for (int k = 0; k < year; k++) {
					tmp2 += tmp * rate;
					tmp -= charge;
				}
				tmp += tmp2;
			}
			
			maxim = maxim < tmp ? tmp : maxim;
		}
		cout << maxim << endl;
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int m;
    int ini, fund, ny, n, max;
    int f, charge, i, interest, final;
    double rate;

    cin >> m;
    while(m--) {
	cin >> ini;
	cin >> ny;
	cin >> n;
	max = 0;
	while (n--) {

	    cin >> f >> rate >> charge;
	    interest = 0;
	    fund = ini;
	    for (i = 0; i < ny; i++) {
		if (f) {
		    fund += fund * rate - charge;
		} else {
		    interest += fund * rate;
		    fund -= charge;
		}
	    }
	    if (f) {
		final = fund;
	    } else {
		final = fund + interest;
	    }
	    if (max < final)
		max = final;
	}
	cout << max << endl;
    }
    return 0;
}
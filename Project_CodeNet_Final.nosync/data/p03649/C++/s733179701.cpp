#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iterator>
#include <set>
#include <functional>

using namespace std;

#define DT long long
#define forn(i,n)for(i=0;i<n;i++)
#define forc(i,c,n)for(i=c;i<=n;i++)

int main() {
	ifstream fin("Text.txt");
	int i, j, q;
	DT a, b, c, d, p, n, m, k, s = 0, t = 0, tt = 0, ss = 0, r;
	//scanf("%I64d", &n);
	//scanf_s("%d", &n);
	cin >> n;
	vector<DT>vc(n),vd(n);
	forn(i, n) {
		cin >> vd[i];
	}
	t = n;
	while (t>0) {
		t = 0;
		forn(i, n) {
			a = vd[i];
			vd[i] = a%n;
			vc[i] = a / n;
			t += vc[i];
		}
		forn(i, n) {
			vd[i] += (t - vc[i]);;
		}
		tt += t;
	}
	cout << tt << endl;
	return 0;
}
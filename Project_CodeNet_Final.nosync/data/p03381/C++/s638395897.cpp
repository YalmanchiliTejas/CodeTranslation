#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

#define ul unsigned long long
#define ull list<ul>

//#define DEBUG

int main() {
	ul n;
	cin >> n;

	ul buf;
	ull x_sorted, x;
	for (ul a=0;a<n;a++) {
		cin >> buf;
		x_sorted.push_back(buf);
		x.push_back(buf);
	}
	x_sorted.sort();

	ull::iterator itr_xs, itr_x;
	itr_xs = x_sorted.begin();
	itr_x = x.begin();
	
#ifdef DEBUG
	for (;itr_xs != x_sorted.end();++itr_xs)  cout << *itr_xs << " ";
#endif //DEBUG

	ul cs[2];
	for (ul c=0;c<(n/2-1);c++) ++itr_xs;
	cs[0] = *itr_xs;
	++itr_xs;
	cs[1]=*itr_xs;

	if (cs[0]==cs[1])
		for (ul d=0;d<n;d++) cout << cs[0] << endl;
	else {
		for (;itr_x!=x.end();++itr_x) {
			if (*itr_x < cs[1]) cout << cs[1] << endl;
			else cout << cs[0] << endl;
		}
	}

	return 0;
}

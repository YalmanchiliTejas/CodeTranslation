#include<iostream>
#include<string>
using namespace std;

int main() {
	int na;
	while (cin >> na, na) {
		int t = 1,n=5,s=2,w=4,e=3,b=6;
		int tsum = 1;
		for (int i = 0;i < na;i++) {
			string sa;
			cin >> sa;
			if (sa == "North") {
				int a[4] = { t,s,b,n };
				t = a[1];
				s = a[2];
				b = a[3];
				n = a[0];
				tsum += t;
			}
			else if (sa == "East") {
				int a[4] = { t,e,b,w };
				t = a[3];
				e = a[0];
				b = a[1];
				w = a[2];
				tsum += t;
			}
			else if (sa == "West") {
				int a[4] = { t,w,b,e };
				t = a[3];
				w = a[0];
				b = a[1];
				e = a[2];
				tsum += t;
			}
			else if (sa == "South") {
				int a[4] = { t,s,b,n };
				t = a[3];
				s = a[0];
				b = a[1];
				n = a[2];
				tsum += t;
			}
			else if (sa == "Right") {
				int a[4] = { s,e,n,w };
				s = a[1];
				e = a[2];
				n = a[3];
				w = a[0];
				tsum += t;
			}
			else {
				int a[4] = { s,e,n,w };
				s = a[3];
				e = a[0];
				n = a[1];
				w = a[2];
				tsum += t;
			}
		}
		cout << tsum << endl;
	}
	return 0;
}
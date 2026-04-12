#include <iostream>
#include <string>
using namespace std;

int main()
{	
	int n;
	
	cin >> n;
	
	while (n > 0) {
		string s;
		int m = 1, u = 1, f = 2, r = 3, t;

		for (int i = 0; i < n; i++) {
			cin >> s;

			if (s == "North") {
				t = u;
				u = f;
				f = 7 - t;
			}
			else if (s == "East") {
				t = u;
				u = 7 - r;
				r = t;
			}
			else if (s == "West") {
				t = u;
				u = r;
				r = 7 - t;
			}
			else if (s == "South") {
				t = u;
				u = 7 - f;
				f = t;
			}
			else if (s == "Right") {
				t = f;
				f = r;
				r = 7 - t;
			}
			else if (s == "Left") {
				t = f;
				f = 7 - r;
				r = t;
			}

			m += u;
		}

		cout << m << endl;
		
		cin >> n;
	}
	
	return 0;
}

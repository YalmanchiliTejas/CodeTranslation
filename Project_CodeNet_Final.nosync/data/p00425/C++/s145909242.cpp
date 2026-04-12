#include <iostream>

using namespace std;

int main()
{
	int f = 1, l = 4, r = 3, t = 5, b = 2, n;
	int ans;
	string com;

	while (cin >> n){
		if (n == 0) break;
		ans = 1;
	  f = 1;
	 	l = 4;
	 	r = 3;
	 	t = 5;
	 	b = 2;
		for (int i = 0; i < n; i++){
			cin >> com;
			if (com == "North"){
				t = f;
				f = b;
				b = 7 - t;
			}
			else if (com == "East"){
				r = f;
				f = l;
				l = 7 - r;
			}
			else if (com == "West"){
				l = f;
				f = r;
				r = 7 - l;
			}
			else if (com == "South"){
				b = f;
				f = t;
				t = 7 - b;
			}
			else if (com == "Right"){
				r = t;
				t = l;
				l = b;
				b = 7 - t;
			}
			else if (com == "Left"){
				r = b;
				b = l;
				l = t;
				t = 7 - b;
			}
			//cout << ans << endl;

			ans += f;
		}
		cout << ans << endl;
	}
	return (0);
}
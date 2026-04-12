#include<iostream>
#include<string>
using namespace std;

int main()
{
	bool k[200]{};
	string c = "yuiophjklnm";
	for (char d : c)k[d] = true;
	string a;
	while (cin >> a, a != "#") {
		bool b = k[a[0]];
		int sum = 0;
		for (int i = 1; i < a.length(); i++) {
			if (k[a[i]] != b) { b = k[a[i]]; sum++; }
		}
		cout << sum << endl;
	}
}
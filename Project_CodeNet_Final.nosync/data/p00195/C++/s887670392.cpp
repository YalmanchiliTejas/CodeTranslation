#include<iostream>
using namespace std;
int main() {
	int s1, s2;
	while (cin >> s1 >> s2&&s1 != 0&&s2 != 0) {
		int a[5];
		a[0] = s1 + s2;
		for (int i = 1; i < 5; i++) {
			cin >> s1 >> s2;
			a[i] = s1 + s2;
		}
		char b;
		int max=0;
		for (int i = 0; i < 5; i++) {
			if (max<a[i])
			{
				max = a[i];
				b = (char)(int)'A' + i;
			}
		}
		cout << b <<" "<<max<< endl;
	}
}
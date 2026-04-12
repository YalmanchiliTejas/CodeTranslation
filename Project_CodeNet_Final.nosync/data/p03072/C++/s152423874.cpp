#include<iostream>
using namespace std;
int main() {
	int a, b[20],c=0,p=0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < a; i++) {
		for (int j = 0; j < i; j++) {
			if (b[i] < b[j])c++;
		}
		if (c==0)p++;
		c = 0;
	}
	cout << p + 1 << endl;

	return 0;

}
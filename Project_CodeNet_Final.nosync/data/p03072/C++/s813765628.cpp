#include <iostream>
using namespace std;

int main() {
	int num, Harray[100], count = 1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> Harray[i];
	}
	int high = Harray[0];
	for (int i = 1; i < num; i++) {
		if (Harray[i] >= Harray[i - 1] && Harray[i] >= high) {
			count++;
			high = Harray[i];
		}
	}
	cout << count << endl;
}
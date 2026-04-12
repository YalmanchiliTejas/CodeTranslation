#include <iostream>
using namespace std;

int main() {
	int num_of_mt;
	int max = 0;
	int height = 0;
	int count = 0;

	cin >> num_of_mt;
	for (int i = 0; i < num_of_mt; i++) {
		cin >> height;
		if (height >= max)
			count++;
		if (max < height)
			max = height;
	}

	cout << count << endl;

	return 0;
}
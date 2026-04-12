#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main(){
	int n;
	int tmp;

	cin >> n;

	vector<int> vals(n);

	// read values
	for (size_t i = 0; i < n; ++i) {
		cin >> tmp;
		vals.at(i) = tmp;
	}

	int return_value = 0;

	// some processing here
	int max = 0;
	for (size_t i = 0; i < n; ++i) {
		if (max <= vals.at(i)) {
			return_value++;
			max = vals.at(i);
		}
	}

	cout << return_value << endl;
	
	return 0;
}
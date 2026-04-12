#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>
#include <numeric>

using namespace std;

vector<pair<long long int, long long int>> getPrimeElements(long long int num) {

	long long int firstnum = num;

	vector<pair<long long int, long long int>> result;
	pair<long long int, long long int> wk;

	if (num % 2 == 0) {
		wk.first = 2;
		wk.second = 0;
		while (num % 2 == 0) {
			wk.second++;
			num /= 2;
		}

		result.push_back(wk);
	}

	long long int waru = 3;

	while (true) {

		if (num % waru == 0) {
			wk.first = waru;
			wk.second = 0;
			while (num % waru == 0) {
				wk.second++;
				num /= waru;
			}

			result.push_back(wk);
		}
		waru += 2;

		if (waru * waru > num) break;

	}

	if (num != 1) {
		wk.first = num;
		wk.second = 1;
		result.push_back(wk);

	}

	return result;
}


int getKeta(int num) {

	if (num == 0)return 1;

	int res = 0;

	while (num > 0) {
		num /= 10;
		res++;
	}

	return res;
}

vector<int> bunkai(int num) {

	string str = to_string(num);
	vector<int> res;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i] - '0';
		res.push_back(a);
	}

	return res;

}


int main()
{
    
	int h, w;
	cin >> h >> w;

	string str;
	int sharp = 0;
	for (int i = 0; i < h; i++) {
		cin >> str;

		for (auto& i : str) {
			if (i == '#')sharp++;
		}
	}

	if (sharp == h + w - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;

}



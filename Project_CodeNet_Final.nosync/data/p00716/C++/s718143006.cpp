#include <iostream>
#include <cstdio>
using namespace std;

enum tag_type {tanri, fukuri};

int main() {
	int m;
	int year;
	int n;
	int type;
	double riritsu;
	int cost;
	long genpon;

	cin >> m;
	for(int _i; _i < m; _i++) {
		long tmp;
		long max = 0;

		cin >> genpon >> year >> n;

		for(int i = 0; i < n; i++) {
			cin >> type;
			cin >> riritsu;
			cin >> cost;

			tmp = genpon;
			if(type == tanri) {
				int sum_rishi = 0;
				for(int j = 0; j < year; j++) {
					int rishi = tmp * riritsu;
					tmp -= cost;
					sum_rishi += rishi;
				}
				tmp += sum_rishi;
			}

			else {
				for(int j = 0; j < year; j++) {
					tmp = tmp + tmp * riritsu - cost;
				}
			}

			if(tmp > max)
				max = tmp;
		}

		cout << max << endl;
	}

	return 0;
}
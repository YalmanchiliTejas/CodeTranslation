#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{

	int N;
	cin >> N;
	
	vector<int> H;

	int count;
	int max;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		H.push_back(tmp);
	}

	max = H[0];
	count = 1;
	for (int i = 1; i < N; i++) {
		if (H[i] >= max) {
			count++;
			max = H[i];
		}
		else {

		}
	}


	std::cout << count;

//	std::cout << coin; 
}
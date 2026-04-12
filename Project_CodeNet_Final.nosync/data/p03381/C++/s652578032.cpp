#include <cstring>
#include <cstdint>
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <limits>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <random>
#include <functional>
#include<algorithm>
#include <array>
#include<random>
using namespace std;

int main() {
	uint32_t N;
	cin >> N;
	vector<uint32_t> in(N);
	for (uint32_t i = 0; i < N; i++)
	{
		cin >> in[i];
	}
	vector<uint32_t>  sorted = in;
	std::sort(sorted.begin(), sorted.end());
	for (uint32_t i = 0; i < N; i++)
	{
		if (in[i] <= sorted[N / 2 - 1])cout << sorted[N / 2] << endl;
		else cout << sorted[N / 2 - 1] << endl;
	}

	return 0;
}
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
using namespace std;

int main() {
	string str;
	cin >> str;
	bool b = false;
	for (size_t i = 0; i + 1< str.size(); i++)
	{
		if (str[i] == 'A') {
			i++;
			if (str[i] == 'C')b = true;
		}
	}
	cout << ((b) ? ("Yes") : ("No"));
	return 0;
}
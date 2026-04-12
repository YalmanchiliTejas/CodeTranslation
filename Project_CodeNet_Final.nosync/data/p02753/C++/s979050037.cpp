#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (auto ss : s) {
		if (ss == 'A')
			a++;
		else
			b++;
	}
	if (a == 3 || b == 3)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}








#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
#include <memory.h>

// pi = atan(1)*4;

using namespace std;

int main(void)
{
	char c;

	cin >> c;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		cout << "vowel" << '\n';
	}
	else
	{
		cout << "consonant" << '\n';
	}

	return 0;
}
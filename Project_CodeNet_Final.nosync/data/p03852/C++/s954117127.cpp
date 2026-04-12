#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <numeric>

#include <map>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <bitset>

#define INF 100100100

typedef long long int llint;

using namespace std;

typedef pair<int, int>Pii;

char mother[5] = { 'a','i','u','e','o' };

int main() {
	char c;
	cin >> c;
	for (int i = 0; i < 5; i++) {
		if (mother[i] == c) {
			puts("vowel");
			return 0;
		}
	}
	puts("consonant");
	return 0;
}
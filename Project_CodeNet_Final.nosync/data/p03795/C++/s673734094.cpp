#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <utility>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << n * 800 - 200 * (n / 15);
}
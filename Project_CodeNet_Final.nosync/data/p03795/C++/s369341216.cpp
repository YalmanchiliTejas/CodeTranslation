#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>

#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define max(a,b) (a < b ? b : a)
#define min(a,b) (a > b ? b : a)

using namespace std;


int main() {
	int N;
	cin >> N;
	cout << 800 * N - (N / 15) * 200;
	return 0;
}

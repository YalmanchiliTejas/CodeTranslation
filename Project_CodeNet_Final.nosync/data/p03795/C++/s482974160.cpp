#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstdio>
#define rep(i, n) for(long long i = 0;(i) < (n);(i)++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
	ll N;
	cin >> N;
	cout << N * 800 - (floor((double)N / 15) * 200) << endl;
	return 0;
}
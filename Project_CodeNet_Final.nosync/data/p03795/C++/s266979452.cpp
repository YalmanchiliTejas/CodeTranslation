#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;
using namespace std;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;

const double EPS = 1e-8;

int main()
{
	ll N=0;

	cin >> N;

	cout << 800*N-(N/15)*200;
	
	return 0;
}

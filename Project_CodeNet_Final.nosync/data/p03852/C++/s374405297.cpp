#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	string memo = "aeiou";
	char cc;
	cin >> cc;
	for(int64 ii = 0;ii < 5;ii++)
	{
		if(cc == memo[ii])
		{
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef vector<int> vint;
typedef vector<string> vstr;




int main()
{
	int N,num;
	cin >> N;
	num = N / 15;
	cout << N * 800 - num * 200 << endl;
}
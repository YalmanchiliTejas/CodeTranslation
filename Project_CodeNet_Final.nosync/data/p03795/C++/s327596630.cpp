#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cout << 800 * N - (N / 15) * 200 << endl;
}
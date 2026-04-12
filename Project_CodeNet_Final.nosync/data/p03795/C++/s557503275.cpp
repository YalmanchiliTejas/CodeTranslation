#include "bits/stdc++.h"
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	cout << 800*n-(int)((double)(n-n%15)/15.0*200) << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <istream>
#define rep0(i,n) for (int i = 0; i <= (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define vec vector<int>a(n)
#define soot(a) sort(a.begin(),a.end())
/*int n;
cin >> n;
vector<int>a(n);
rep0(i, n - 1)cin >> a[i];*/
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a *100+ b * 10 + c ;
	if (ans % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
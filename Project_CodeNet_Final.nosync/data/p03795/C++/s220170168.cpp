#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10][10];

int main()
{
	long long money, n, t;
	cin >> n;
	money = n * 800;
	t = n / 15;
	money -= t * 200;
	cout << money;
    return 0;
}
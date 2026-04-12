#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	//scanf("%d", &n);
	cin >> n;

	int rest = n / 15;
	int y = 200 * rest;
	int x = 800 * n;

	printf("%d\n", x - y);

}
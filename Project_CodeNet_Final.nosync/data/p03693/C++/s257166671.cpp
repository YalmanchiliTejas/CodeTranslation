#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue> //C++
#include <string> //C++
#include <iostream> //C++
#include <vector> //C++
#include <algorithm> //C++
using namespace std; //C++
#define rep(i, a, n) for (i = (a); i < (n); i++)



int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x = a * 100 + b * 10 + c;
	if (x % 4 == 0) {
		cout << "YES";
	}
	else cout << "NO";
}
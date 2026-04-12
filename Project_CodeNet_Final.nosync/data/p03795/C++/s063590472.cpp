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


int main()
{
	int n;
	cin >> n;
	int Ans = n * 800 - (n / 15) * 200;

	cout << Ans;
}

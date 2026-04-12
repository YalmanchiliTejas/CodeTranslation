//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define MAX_INT 2100000000
using namespace std;
typedef long long int ll;
//#include "Header.h"
int main()
{
	int n, k,i,j;
	string s;
	cin >> n >> s >> k;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] != s[k-1]) s[i] = '*';
	}
	cout << s << endl;
}

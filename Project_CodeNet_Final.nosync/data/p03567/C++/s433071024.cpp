#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

string s;

int main()
{
	cin >> s;
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] == 'A' && s[i + 1] == 'C') { printf("Yes\n"); return 0; }
	printf("No\n");
	return 0;
}
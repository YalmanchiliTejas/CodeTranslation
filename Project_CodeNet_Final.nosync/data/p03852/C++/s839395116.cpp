#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <stack>

using namespace std;

typedef long long LL;
#define FAST ios::sync_with_stdio(false);
const int MaxN = 105;

int main()
{
	char c;
	cin >> c;
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u')
		cout << "vowel" << endl;
	else 
		cout << "consonant" << endl;
	return 0;
	}
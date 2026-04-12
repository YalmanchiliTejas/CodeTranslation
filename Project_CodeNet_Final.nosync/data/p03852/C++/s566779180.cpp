#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)

const int INF = 100000000;

using namespace std;


int main() {
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')cout << "vowel" << endl;
	else cout << "consonant" << endl;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <array>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

#define INT_MAX 2000000000
#define MOD 1000000007
#define rep(i,a,b) for(i = (a); i < (b); i++)
#define bitget(a,b) (((a) >> (b)) & 1)
#define vint vector<int>
#define vsort(x) sort(x.begin(),x.end())

using int64 = uint64_t;


using namespace std;

int main() {

	int i, j, k;
	string s;
	cin >> s;
	if (s[0] == 'a' | s[0] == 'i' | s[0] == 'u' | s[0] == 'e' | s[0] == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	
	return 0;
}
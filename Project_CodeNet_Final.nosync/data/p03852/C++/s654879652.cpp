#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
#include <complex>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <istream>
//-----------------------------------------------------define--------------------------------------------------------------------//
#define PB push_buck
#define MP make_pair
#define MAX 100000
//-------------------------------------------------------typedef----------------------------------------------------------------//
typedef long long ll;

using namespace std;

char a;
//------------------------------------------------------------------------------------------------------------------------------//
int main() {
	cin >> a;
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}
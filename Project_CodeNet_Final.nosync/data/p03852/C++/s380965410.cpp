#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;
#define rep(i,n) for (int i=0 ; i<(n);i++)
#define INF 1e9+7
int main() {
	string a;
	cin >> a;
	if (a[0] == 'a' || a[0] == 'i' || a[0] == 'u' || a[0] == 'e' || a[0] == 'o')
		cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
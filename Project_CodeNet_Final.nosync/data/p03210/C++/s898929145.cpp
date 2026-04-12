//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define REF(i, s, e) for(int i=s; i>e; i--)
typedef long long ll;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x;
	cin >> x;
	
	if (x == 7 || x == 5 || x == 3) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}
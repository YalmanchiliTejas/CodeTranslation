//#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<set>
#include<limits.h>
#include<list>
#include <cassert>
#include<sstream>
#include<locale>
#include <bitset>
using namespace std;
using ll = long long int;

int main() {
	int n, ans = 0, max = 0,c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c >= max)
			ans++, max = c;
		
	}
	cout << ans;
	return 0;
} 




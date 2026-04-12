#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<list>
#include<cmath>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0])
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;
typedef long long ll;



int main(void) {
	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <utility>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int i, j, k;



int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n = a * 100 + b * 10 + c;
	if (n % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}


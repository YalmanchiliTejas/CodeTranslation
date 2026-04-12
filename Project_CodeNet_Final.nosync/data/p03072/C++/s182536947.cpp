#include <cstdio>
#include <cmath>

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp >= m) {
			m = temp;
			res++;
		}
	}
	cout << res << endl;
}
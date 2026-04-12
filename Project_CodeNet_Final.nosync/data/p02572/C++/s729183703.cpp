#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <stdlib.h> 
#include <stdio.h>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <deque>
#include <stack>
#include <queue>
#include <fstream>
#include <limits>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <sstream>
#include <random>
#include <cassert>

using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

int main(void) {
	cin.tie(0); ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector <long long> v(n);
	ffor(n) cin >> v[i];
	vector <long long> sum_right(n);
	for (int i = n - 2; i >= 0; i--) {
		sum_right[i] = sum_right[i + 1] + v[i + 1];
		sum_right[i] %= INF;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (v[i] * sum_right[i]);
		ans %= INF;
	}
	cout << ans;

}
	




/*
C:\Users\User\Desktop\comp_programming\final_straw_after_this_im_switching_to_vs_code\final_straw_after_this_im_switching_to_vs_code.cpp
*/
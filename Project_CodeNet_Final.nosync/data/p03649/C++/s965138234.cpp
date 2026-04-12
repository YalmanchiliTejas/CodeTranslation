#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int64_t a[n];
	for(int64_t &i:a) cin >> i;
	int64_t sum = accumulate(a, a + n, 0ll), x = max(int64_t(0), sum - n * (n - 1));
	for(int64_t &i:a) i += x;
	int64_t l = 0, r = sum;
	while(1 < r - l){
		int64_t mid = (l + r) / 2, puni = 0;
		for(int64_t &i:a) puni += max(int64_t(0), (i - mid) / (n + 1));
		(puni <= x ? r : l) = mid;
	}
	int64_t times = 0;
	for(int64_t &i:a) times += max(int64_t(0), (i - r) / (n + 1));
	for(int64_t &i:a) i -= (n + 1) * max(int64_t(0), (i - r) / (n + 1));
	for(; times < x; times++) *max_element(a, a + n) -= (n + 1);
	while(n <= *max_element(a, a + n)){
		for(int64_t &i:a) i++;
		*max_element(a, a + n) -= n + 1;
		times++;
	}
	cout << times << endl;
}
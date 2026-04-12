#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	int_least32_t n;
	cin >> n;

	vector<int_least32_t> v( n );
	for(auto& x : v) {
		cin >> x;
	}

	for(int_least32_t i = v.size() - 1; i >= 0; i -= 2) {
		cout << v[i] << ' ';
	}
	if(n % 2 == 1) {
		for(auto i = 1U; i < v.size(); i+=2) {
			cout << v[i] << ' ';
		}
	}
	else {
		for(auto i = 0U; i < v.size(); i+=2) {
			cout << v[i] << ' ';
		}
	}
}

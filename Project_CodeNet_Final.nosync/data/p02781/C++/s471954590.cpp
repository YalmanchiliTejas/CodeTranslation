#include <iostream>
#include <string>
#define DEBUG(x) std::cout << #x << " is" << (x) << std::endl

long long pow(long long x, long long y) {
	long long ret = 1;
	while(y != 0) {
		if(y % 2 == 1) {
			ret *= x;
		}
		x *= x;
		y >>= 1;
	}
	return ret;
}

long long binomial(long long n, long long k) {
  	if(n < k) return 0;
	long long ret = 1;
	for(int i = 0;i < k;i++) {
		ret = ret * (n - i) / (i + 1);
	}
	return ret;
}

long long count(std::string str, int k){
	int size = str.size();
	if(k == 0 || k > size) {
		return 0;
	}
	long long ret = 0;
	
	if(size > k) ret += binomial(size - 1, k) * pow(9, k);
	ret += (str[0] - '0' - 1) * binomial(size - 1, k - 1) * pow(9, k - 1);
  	if(k == 1) ret++;
  	//DEBUG(ret);
	int index = 1;
	while(index < size && str[index] == '0') index++;
	if(index != size) ret += count(str.substr(index), k - 1);
	
	return ret;
}

int main() {
	std::string n;
	std::cin >> n;
	
	int k;
	std::cin >> k;
	
	std::cout << count(n, k) << std::endl;
	return 0;
}
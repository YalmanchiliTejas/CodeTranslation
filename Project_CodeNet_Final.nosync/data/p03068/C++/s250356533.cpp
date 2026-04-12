#include <iostream>
#include <string>

int main() {
    std::string s;
    int n, k;
  	std::cin >> n >> s >> k;
    const char& c = s[k - 1];
  	for (int i = 0; i < n; ++i) {
    	std::cout << ((s[i] != c) ? '*' : s[i]);
    }
	return 0;
}
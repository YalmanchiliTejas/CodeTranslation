#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
 
int main() {
	int n;
	std::cin >> n;
	std::string a, s;
	std::vector<std::string> str;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		str.emplace_back(a);
	}
	for (int i = 'a'; i <= 'z'; i++) {
		int cmin = 1000;
		for (int j = 0; j < n; j++) {
			int calphabet = 0;
			for (int o = 0; o < str[j].size(); o++) {
				if (str[j][o] == i) {
					calphabet++;
				}
			}
			if (calphabet <= cmin) {
				cmin = calphabet;
			}
		}
		for (int j = 0; j < cmin; j++) {
			s += i;
		}
	}
	std::cout << s << std::endl;
}
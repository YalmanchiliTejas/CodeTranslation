#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<cmath>
#define INF 

typedef long long ll;

int main() {
	char a;
	std::cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') {
		std::cout << "vowel" << std::endl;
	}
	else {	
		std::cout << "consonant" << std::endl;
	}
	return 0;
}
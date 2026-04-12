#include<iostream>
#include <algorithm>
#include <string>
#define syso(s) std::cout<<s<<endl;
#define sc(i) std::cin>>i;
using namespace std;
int main() {
	string str;
	sc(str)
	string ans="consonant";
	if (str == "a" || str == "e" || str == "i" || str == "o" || str == "u") {
		ans="vowel";
	}
	syso(ans)
	return 0;
}
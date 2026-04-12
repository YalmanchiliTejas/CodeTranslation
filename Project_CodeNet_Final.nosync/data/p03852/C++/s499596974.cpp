#include <iostream>
#include <string>

int main()
{
	std::string s; std::cin >> s;
	std::string ans("consonant");
	if(s=="a" || s=="e" || s=="i" || s=="o" || s=="u") ans = "vowel";
	std::cout << ans << std::endl;

	return 0;
}
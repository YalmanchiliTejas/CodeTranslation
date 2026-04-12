#include <bits/stdc++.h>
int main(){
	std::string s;
  	std::cin >> s;
  	std::sort(s.begin(), s.end());
  	if(s[0] == s[2]) std::cout << "No" << '\n';
  	else std::cout << "Yes" << '\n';
}
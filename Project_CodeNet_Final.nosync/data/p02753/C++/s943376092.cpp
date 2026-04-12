#include<iostream>
int main()
{
	std::string s;
  	std::cin >> s;
  	if(s[0] == s[1] && s[1] == s[2])
    {
      std::cout << "No\n";
    }
  	else
    {
      std::cout << "Yes\n";
    }
  return 0;
}
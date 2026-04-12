#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

int main()
{
  	int Num = 0;
	std::cin >> Num;
 	std::vector<int> InCharacter(26,0xFF);

  	for(int i = 0; i< Num;i++)
    {
      std::string str;
      std::cin >> str;
      std::vector<int> Count(26,0);
      for(const auto& ch : str)
      {
        Count[ch-'a']++;
      }
      for(auto chari=0; chari < Count.size();chari++)
      {
        InCharacter[chari] = std::min( InCharacter[chari],Count[chari]);
      }
    }
    char OutputStr = 'a';
	for (auto&& StrNum : InCharacter)
	{
		for (int i = 0; i < StrNum ; i++)
		{
			std::cout << OutputStr;
		}
		OutputStr++;
	}
  
    std::cout <<std::endl;
      
   	return 0;

}
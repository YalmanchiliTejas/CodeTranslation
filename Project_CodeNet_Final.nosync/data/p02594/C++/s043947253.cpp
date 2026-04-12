#include <iostream>
bool ac(int temp)
{
  if(temp<30)
    return false;
  else
    return true;
}

int main()
{
  int temp;
  std::cin>>temp;
  bool result=ac(temp);
  if(result)
    std::cout<<"Yes";
  else
    std::cout<<"No";
}
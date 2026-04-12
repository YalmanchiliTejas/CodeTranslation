#include <iostream>
void airConditioner(int temp, bool &acOn){
	if (temp >= 30)
		acOn = true;
}
int main()
{
  int X = 0;
  bool isAirConditioner = false;
	std::cin >> X;
	airConditioner(X, isAirConditioner);
		if(isAirConditioner)
			std::cout << "Yes";
		else
			std::cout << "No";
  return 0;
}
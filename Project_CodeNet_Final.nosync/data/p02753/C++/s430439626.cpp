#include<iostream>
#include<string>
using namespace std;
int main()
{
	string dog;
	cin >> dog;
	int a=0, b = 0;
	for (int i = 0; i < 3; i++)
	{
		if (dog[i] =='A')
		{
			a = 1;
			 
		}
		else if (dog[i] =='B')
		{
			b = 1;
		 
		}
	}
	if (a==1&&b==1)cout << "Yes";
	else cout << "No";

    return 0;
}


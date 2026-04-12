#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	string r,g,b;
	string combine;
	int n;
 
	cin >> r >> g >> b;
	combine = r + g+b;
	n = atoi(combine.c_str());
 
	if (n % 4 == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	system("pause");
	return 0;
}
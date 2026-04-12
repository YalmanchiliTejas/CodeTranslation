#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	bool flag = false;
	for (auto i = s.begin(); i != s.end() - 1; ++i)
		if (*i == 'A'&&*(i + 1) == 'C')
			flag = true;
	if (flag)
		puts("Yes");
	else
		puts("No");
	//system("pause");
}
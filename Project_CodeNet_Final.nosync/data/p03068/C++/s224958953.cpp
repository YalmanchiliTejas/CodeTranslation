#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,k;
	string s;
	cin >> n >> s >> k;
	char ch = s[k-1];
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] != ch)
			cout << '*';
		else
			cout << s[i];
	}
	cout << endl;
	return 0;
}

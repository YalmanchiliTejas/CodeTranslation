#include<iostream>

using namespace std;

int main(void)
{
	char c;
	cin >> c;
	char x[5]={'a','e','i','o','u'};
	for(int i=1;i<=5;i++)
	{
		if(c==x[i-1])
		{
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
}
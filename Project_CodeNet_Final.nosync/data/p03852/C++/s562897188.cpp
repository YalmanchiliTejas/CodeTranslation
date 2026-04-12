#include<iostream>
using namespace std;
int main()
{
	char n;
	cin>>n;
	if(n==97 || n==101 || n==105 || n==111 || n==117)
	{
		cout<<"vowel";
		return 0;
	}
	cout<<"consonant";
	return 0;
 } 
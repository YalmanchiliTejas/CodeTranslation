#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char a;
	while(cin>>a)
	{
		if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		{
			cout<<"vowel"<<endl;
		}
		else
			cout<<"consonant"<<endl;
	}
}

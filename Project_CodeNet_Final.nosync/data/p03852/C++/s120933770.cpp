#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
char a;
int main()
{
	cin>>a;
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	{
		cout<<"vowel"<<endl;
		return 0;
	}
	else
	{
		cout<<"consonant";
		return 0;
	}
    return 0;
}
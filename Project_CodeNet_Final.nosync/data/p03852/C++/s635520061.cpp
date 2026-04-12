#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	char c;
	cin>>c;
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
	{
		cout<<"vowel"<<endl;
	}
	else
	{
		cout<<"consonant"<<endl;
	}
	return 0;
}
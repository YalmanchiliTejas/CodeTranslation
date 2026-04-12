#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
char ch;
int main()
{
	cin>>ch;
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
	cout<<"vowel";
	else
	cout<<"consonant";
	cout<<endl;
	return 0;
}
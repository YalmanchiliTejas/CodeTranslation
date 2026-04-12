#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
char a;
int main()
{
	cin>>a;
	if(a=='a') cout<<"vowel"<<endl;
	if(a=='e') cout<<"vowel"<<endl;
	if(a=='i') cout<<"vowel"<<endl;
	if(a=='o') cout<<"vowel"<<endl;
	if(a=='u') cout<<"vowel"<<endl;
	
	if(a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u')cout<<"consonant"<<endl;
	return 0;
 } 
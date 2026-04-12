#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	char a;
	cin>>a;
	if(a==97 || a==101 || a==105 || a==111 || a==117)	cout<<"vowel"<<endl;
	else	cout<<"consonant"<<endl;
	return 0;
}
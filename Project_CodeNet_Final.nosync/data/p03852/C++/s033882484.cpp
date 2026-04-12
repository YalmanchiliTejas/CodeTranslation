#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
char ch;
int main()
{
	cin>>ch;
	if(ch-96==1||ch-96==5||ch-96==9||ch-96==15||ch-96==21) cout<<"vowel";
	else cout<<"consonant";
	cout<<endl;
	
	return 0;
}
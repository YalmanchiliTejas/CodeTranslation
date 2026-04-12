#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
char ch;
int main()
{
	cin>>ch;
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')cout<<"vowel";
	else cout<<"consonant";
    return 0;
}

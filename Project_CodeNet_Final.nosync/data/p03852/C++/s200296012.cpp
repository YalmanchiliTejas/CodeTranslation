#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char s[1001],st[1001];
int main()
{
   scanf("%s",s);
	if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')
	{
		cout<<"vowel"<<endl;
	}
	else cout<<"consonant"<<endl;
    return 0;
}
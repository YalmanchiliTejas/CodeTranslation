#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;
char c;
int main()
{
	cin>>c;
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cout<<"vowel";
	else cout<<"consonant";
	cout<<"\n";
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char ch[5]={'a','e','i','o','u'},s;
int main()
{
	s=getchar();
	for(int i=0;i<5;i++)
	{
		if(s==ch[i])
		{
			cout<<"vowel"<<endl;
			return 0;
		}
	}
	cout<<"consonant"<<endl;
	return 0;
}

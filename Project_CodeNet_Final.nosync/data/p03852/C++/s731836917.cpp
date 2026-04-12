#include<bits/stdc++.h>
using namespace std;

int main()
{
	char ch[10];
	while(cin>>ch){
		if(ch[0]=='a'||ch[0]=='e'||ch[0]=='i'||ch[0]=='o'||ch[0]=='u')
		cout<<"vowel"<<endl;
		else
		cout<<"consonant"<<endl;
	}
	return 0;
}
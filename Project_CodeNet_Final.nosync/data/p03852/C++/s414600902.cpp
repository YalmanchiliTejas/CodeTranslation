#include<iostream>
using namespace std;
int main()
{
	char a;
	int b;
	cin>>a;
	b=a;
	if(b==97||b==101||b==105||b==111||b==117)
	{
		cout<<"vowel"<<endl;
	}
	else cout<<"consonant"<<endl;
	return 0;
} 
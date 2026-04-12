#include<iostream>
using namespace std;

int main(){
	int i;
	char c;
	char array[5]={'a','e','i','o','u'};

	cin >>c;
	for(i=0;i<5;i++)if(c==array[i])break;
	if(i==5)cout<<"consonant"<<endl;
	else cout<<"vowel"<<endl;
	return 0;

}
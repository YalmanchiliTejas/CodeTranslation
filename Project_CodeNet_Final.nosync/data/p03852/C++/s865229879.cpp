#include<iostream>
using namespace std;

int main()
{
char A[5]={'a','e','i','o','u'};
bool flag;
char s;
cin>>s;
for(int i=0;i<5;i++){
	if(A[i]==s){
		flag=true;
		break;}

	else{
		flag=false;}
	
}
if(flag==true)
	cout<<"vowel";
else if(flag==false)
	cout<<"consonant";
}
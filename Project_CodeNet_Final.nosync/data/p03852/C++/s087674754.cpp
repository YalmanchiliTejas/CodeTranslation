#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	bool a[]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
	char c;
	cin>>c;
	int n=c-'a';
	if(a[n])cout<<"vowel"<<endl;
	else cout<<"consonant"<<endl;
	return 0;
}
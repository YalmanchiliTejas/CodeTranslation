#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath> 
#define ll long long
using namespace std;
int main(){
	char ch;
	while(cin>>ch){
		if(ch=='a' || ch=='o' || ch=='e' || ch=='i' || ch=='u')
			cout<<"vowel"<<endl;
		else
			cout<<"consonant"<<endl;
	}
	
	
	return 0;
}
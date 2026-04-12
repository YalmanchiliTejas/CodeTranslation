#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;
int main (){
	string s;
	cin>>s;
	if (s.at(0) ==s.at(1) && s.at(1) ==s.at(2)){
		printf("No");
	}
	else{
		printf("Yes");
	}
}

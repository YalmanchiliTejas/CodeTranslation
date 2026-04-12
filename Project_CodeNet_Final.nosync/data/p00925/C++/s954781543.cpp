#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
typedef string::const_iterator State;

int expression(State &begin);
int expression2(State &begin);
int term(State &begin);
int number(State &begin);

int number(State &begin){
	int ret=0;
	while(isdigit(*begin)){
		ret*=10;
		ret+=*begin-'0';
		begin++;
	}
	return ret;
}

int term(State &begin){
	int ret=number(begin);
	while(1){
		if(*begin=='*'){
			begin++;
			ret*=number(begin);
		}else{
			break;
		}
	}
	return ret;
}

int expression(State &begin){
	int ret=term(begin);
	while(1){
		if(*begin=='+'){
			begin++;
			ret+=term(begin);
		}else{
			break;
		}
	}
	return ret;
}

int expression2(State &begin){
	int ret=number(begin);
	while(1){
		if(*begin=='+'){
			begin++;
			ret+=number(begin);
		}else if(*begin=='*'){
			begin++;
			ret*=number(begin);
		}else{
			break;
		}
	}
	return ret;
}



int main(void){
	string str;
	cin >> str;
	State begin=str.begin();
	int ans=expression(begin);
	begin=str.begin();
	int ans2=expression2(begin);
	int n;
	scanf("%d",&n);
	if(n==ans && n==ans2)printf("U\n");
	if(n==ans && n!=ans2)printf("M\n");
	if(n!=ans && n==ans2)printf("L\n");
	if(n!=ans && n!=ans2)printf("I\n");	
	return 0;
}
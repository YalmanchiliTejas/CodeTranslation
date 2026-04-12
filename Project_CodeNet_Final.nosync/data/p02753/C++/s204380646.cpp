#include<bits/stdc++.h>
using namespace std;

string S;

int main(){
	cin>>S;
	int a=0;
	for(char c:S){
		a+=c;
	}
	if(a%3){
		puts("Yes");
	}
	else{
		puts("No");
	}
}

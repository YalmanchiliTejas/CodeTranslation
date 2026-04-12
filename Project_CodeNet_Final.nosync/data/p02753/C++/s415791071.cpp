#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int syc(long i,long Min,long Max){
	if(Min <= i && i <= Max){
		return 1;
	}else{
		exit(1);
		//return 0;
	}
}

int main(){
	string s;
	cin >> s;
	int a=0,b=0;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='A'){
			a++;
		}
		if(s[i]=='B'){
			b++;
		}
	}
	
	if(a>0 && b>0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
}

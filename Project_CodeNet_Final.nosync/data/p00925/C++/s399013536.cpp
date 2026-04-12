#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

char s[20];
int query;

int M(){
	int i;
	int a = s[0]-'0',b,c;
	for( i = 1; i < strlen(s); i++ ){
		if( i%2 ){
			b = s[i+1]-'0';
			if( s[i] == '+'){
				while( i+3 < strlen(s) && s[i+2] == '*' ){
					c = s[i+3]-'0';
					b *= c;
					i += 2;
				}
				a += b;
			}
			else
				a *= b;
		}
	}
	return a;
}
int L(){
	int i;
	int a = s[0]-'0',b;
	
	for( i = 1; i < strlen(s); i++ ){
		if( i%2 ){
			b = s[i+1]-'0';
			if( s[i] == '+')
				a += b;
			else
				a *= b;
		}
	}
	return a;
}

int main(){
	cin >> s >> query;
	//cout << M() << " " << L() << endl;
	if( M() == query && L() == query )
		cout << "U";
	else if( M() == query ){
		cout << "M";
	}
	else if( L() == query ){
		cout << "L";
	}
	else{
		cout << "I";
	}
	cout << endl;
	return 0;
}
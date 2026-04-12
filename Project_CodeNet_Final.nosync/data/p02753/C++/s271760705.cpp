#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std ;

char s[4] ;

int main(){
	std :: cin >> s + 1 ;
	if (s[1] == s[2] && s[2] == s[3])
		std :: cout << "No" ; else std :: cout << "Yes" << endl ;
}
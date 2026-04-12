#include<bits/stdc++.h>
using namespace std;

char a , b , c; 

int main(){
	scanf("%c%c%c" , &a , &b , &c);
	if(a == b && b == c) puts("No");
	else puts("Yes");
	return 0;
}
/* Bismillahirrahmanirrahim */
#include<bits/stdc++.h>
#define forA for(int i=0; i<a; i++)
using namespace std;

int main(){
	int a, b;
	char c;
	cin >> a;
	string str;
	cin >> str;
	cin >> b;
	c=str[b-1];
	forA{
		if(str[i]!=c) str[i]='*';
	}
	cout << str;
}

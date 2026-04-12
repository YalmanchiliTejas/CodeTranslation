#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int X;
	cin >> X;
	if(X%5==0 || X%7 == 0){
	cout << "YES" << endl;
	}
	else if(X%3 == 0 && X%6!=0 && X%9 != 0){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

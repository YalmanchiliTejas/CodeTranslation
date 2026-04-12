#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main(){
	int X,Y,Z,people;
	cin >> X >> Y >> Z;
	people = (X-Z)/(Y+Z);
	cout << people << endl;

	return 0;
}
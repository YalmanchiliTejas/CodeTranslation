#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void load(void);
void output(void);

int X;

int main(){
	load();
	output();
	return 0;
}

void load(void){
	cin >> X;
}

void output(void){
	int res;
	if(X >= 30){
		cout << "Yes";
	}else{
		cout << "No";
	}
}
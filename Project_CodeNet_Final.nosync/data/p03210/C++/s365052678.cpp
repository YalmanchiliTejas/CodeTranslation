#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#define INF INT_MAX
using namespace std;

int X;

int main(){
	cin >> X;
	if (X == 3){
		cout << "YES" << endl;
	}
	else if (X == 5){
		cout << "YES" << endl;
	}
	else if (X == 7){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
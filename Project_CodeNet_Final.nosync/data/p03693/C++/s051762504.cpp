#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
int main() {
	int x1,x2,x3;
	int N;
	cin >> x1>>x2>>x3;
	
	N = x1 * 100 + x2 * 10 + x3;
	if (N % 4 == 0) {
		printf("YES");
	}
	else { cout << "NO"; }
	return 0;
}
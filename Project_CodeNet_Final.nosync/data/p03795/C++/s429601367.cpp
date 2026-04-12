#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int x = 800*n;
	int y = 200*(n/15);
	
	printf("%d\n", x-y);
	
	return 0;
}
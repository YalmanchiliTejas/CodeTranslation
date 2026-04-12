#include <iostream>
#include <stdio.h>

int main() {
	int a;
	scanf("%d",&a);
	if (a == 7 || a==5 || a==3) {
		std::cout << "YES";
	}
	else{
		std::cout << "NO";
	}
	
	return 0;
}
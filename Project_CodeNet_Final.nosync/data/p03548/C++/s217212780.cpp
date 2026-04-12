#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<stack>
using namespace std;


int main() {

	int x, y, z, X, num = 0;

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	X = x;
	while (1) {
		if (z <= X) {
			X -= z;
			if (X >= y + z) {
				X -= y;
				num++;
			}
			else { break; }
		}
		else { break; }
	}
	printf("%d", num);

}
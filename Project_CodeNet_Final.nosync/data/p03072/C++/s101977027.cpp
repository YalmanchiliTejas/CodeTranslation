#include<iostream>

int n;
int a=0, b;
int c = 0;

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> b;
		if (a <= b) {
			a = b;
			c++;
		}
	}
	std::cout << c;
}
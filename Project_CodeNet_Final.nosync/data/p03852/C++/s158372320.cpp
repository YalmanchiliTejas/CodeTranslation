#include<algorithm>
#include<array>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<iso646.h>
#include<queue>
#include<stack>
#include<string>
#include<vector>

#define FOR(counter,initial_value,condition) for(int counter = initial_value; counter < condition;counter++)

int main()
{
	char c;
	std::cin >> c;
	std::cout << ((c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o') ? "vowel" : "consonant") << std::endl;
}
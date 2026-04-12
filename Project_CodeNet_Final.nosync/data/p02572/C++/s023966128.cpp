/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces

Compile: g++  -o C.exe C.cpp 
Execute: ./C
*/ 

#include <cstdio>
#include <iostream>
#include <cmath> 
#include <limits> 
#include <iomanip>
#include <cstring> 
#include <bits/stdc++.h>
#include <string>  
using namespace std;

int main() { 	
	int n; 
	unsigned long long 
		sum_squares = 0ULL, 
		a, 
		a2,
		inv_2 = 500000004ULL, 
		mod = 1000000007ULL,
		sum_a = 0ULL,
		result; 
		
	cin >> n; 
	for(int i = 0; i < n; i++) {
		cin >> a; 
		
		// Calculate sum of squares 
		a2 = (a*a) % mod; 
		sum_squares += a2; 
		sum_squares %= mod; 
		
		// Calculate sum of a
		sum_a += a; 
		sum_a %= mod; 
	}
	sum_a *= sum_a; 
	sum_a %= mod; 
	result = (mod + sum_a - sum_squares) % mod; 
	result = (result * inv_2) % mod; 
	
	cout << result << endl; 
	
	return 0; 
} 

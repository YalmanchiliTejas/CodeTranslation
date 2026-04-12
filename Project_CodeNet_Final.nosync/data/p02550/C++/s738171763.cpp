/* [Template].cpp 
Example code to use when starting new code. This particular problem was problem 
977A_Wrong_Subtraction from CodeForces

Compile: g++  -o E.exe E.cpp 
Execute: ./E
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
	long long n, x, m;
	cin >> n >> x >> m;
	
	long long a[100001] = {0}; 
	bool already_visited[100001] = {false};
	a[1] = x;
	already_visited[x] = true;
	long long cycle_starter; 
	long long last_before_cycle_repeats = m; 
	for(int i = 2; 1==1 /*i <= m*/; i++) {
		a[i] = (a[i-1] * a[i-1]) % m; 
		if(already_visited[a[i]]) {
			last_before_cycle_repeats = i-1; 
			cycle_starter = a[i]; 
			break; 
		} else {
			already_visited[a[i]] = true; 
		}
		
		// Checking 
		// cout << a[i] << endl; 
	}
	
	long long s = 0; 
	for(int i = 1; i <= min(n, last_before_cycle_repeats); i++) {
		s += a[i]; 
		
		// Checking 
		// cout << i << "\t" << a[i] << endl; 
	}
	
	
	
	// Figure out the elements and length of cycle
	long long length_cycle = 1; 
	x = (cycle_starter * cycle_starter) % m; 
	long long sum_of_cycle = cycle_starter; 
	vector<long long> cycle_vector; 
	cycle_vector.push_back(cycle_starter); 
	while(x != cycle_starter) {
		length_cycle++; 
		sum_of_cycle += x; 
		cycle_vector.push_back(x); 
		x = (x*x) % m;
		
		// Checking 
		// cout << x << "\t" << cycle_starter << endl; 
	}
	
	long long num_repeats = (n-last_before_cycle_repeats) / length_cycle; 
	long long num_leftover = (n-last_before_cycle_repeats) % length_cycle; 
	
	long long sum_leftover = 0; 
	
	for(int i = 0; i < num_leftover; i++) {
		sum_leftover += cycle_vector[i]; 
	}
	
	long long result = 0; 
	if(n > last_before_cycle_repeats)
		result = s + num_repeats * sum_of_cycle + sum_leftover; 
	else 
		result = s; 
	
	// Checking
	/*
	cout << "Components: " << endl; 
	cout << "s = " << s << endl; 
	cout << "num_repeats = " << num_repeats << endl; 
	cout << "sum_of_cycle = " << sum_of_cycle << endl; 
	*/
	
	cout << result << endl; 
	
	return 0; 
} 

#include <bits/stdc++.h>

#include <iostream>
using namespace std ; 

int main ( ) 
{
	int x ; 
	scanf("%d",&x) ; 
	int payback = (x/15) * 200 ; 
	
	cout << (x*800) - payback ; 
	
		return 0 ; 
}
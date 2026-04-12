#include <iostream>
#include <algorithm>
#include <string> 
#include <string.h>
#include <set>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib> 
using namespace std; 
int main()
{
	int r,g,b;
	cin>>r>>g>>b;
	if((100*r+10*g+b) % 4==0) cout<<"YES";
	else
	cout<<"NO"; 
	return 0;
}
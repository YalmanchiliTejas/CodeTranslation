#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	r=r*100+g*10+b;
	if(r%4==0){printf("YES\n");}
	else{printf("NO\n");}
	
}
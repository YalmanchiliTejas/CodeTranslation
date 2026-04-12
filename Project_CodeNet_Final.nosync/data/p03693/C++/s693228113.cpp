#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;


int n,x,y,z;
int main()
{
	cin>>x>>y>>z;
	n=x*100+y*10+z;
	if(n%4==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
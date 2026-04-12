#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	unsigned int x,y,n;
	scanf("%d",&n);
	x=n*800;
	if(n>=15)
	printf("%d",x-(n/15*200));
	else
	printf("%d",x);
	return 0;}
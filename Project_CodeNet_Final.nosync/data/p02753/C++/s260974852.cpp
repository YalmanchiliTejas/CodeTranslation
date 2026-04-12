/*
我的心脏怦怦跳，监管者就在附近
name:
Algorithm:
writer:Lxs(cdx)
place:
nothing is impossible
*/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include<cmath>
#include<set>
#include<stack>
#include<queue>
#include<unistd.h>
#include<stdio.h>
#include<cstring>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
bool prime(int x){
	 int i;
	 if(x<2) return 0;
	 for(i=2;i*i<=x;i++){
		if(x%i==0){return 0;}
	 }
	 return 1;
}
int main()
{
	string st;
	cin>>st;
	if(st[0]!=st[1]||st[1]!=st[2]||st[0]!=st[2]){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No";
	}
	return 0;
}

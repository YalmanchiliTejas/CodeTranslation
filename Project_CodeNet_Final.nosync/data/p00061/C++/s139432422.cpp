#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int p[100],Score[30]={};
	int n,s;
	int call,rank;
	while(scanf("%d,%d",&n,&s),n|s){
		p[n-1]=s;
		Score[s-1]++;
	}
	
	while(cin>>call){
		rank=0;
		for(int i=29;i>=p[call-1]-1;--i){
			if(Score[i]){
				++rank;
			}
		}
		cout<<rank<<endl;
	}
	
	return 0;
}
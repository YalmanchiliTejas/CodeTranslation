
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <stack>
#include <cctype>

using namespace std;


int main(){

	while(1){
		int n,s,sum,max,min;

		cin>>n;
		if(n==0) break;

		sum=0;
		for(int i=0;i<n;i++){
			cin>>s;
			if(i==0){
				max=s,min=s;
			}
			if(s<min) min=s;
			if(s>max) max=s;
			sum+=s;
		}
		cout<<(sum-max-min)/(n-2)<<endl;
	}	

	return 0;
}
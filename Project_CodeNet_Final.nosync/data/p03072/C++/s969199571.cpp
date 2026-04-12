#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int syc(long i,long Min,long Max){
	if(Min <= i && i <= Max){
		return 1;
	}else{
		exit(1);
		//return 0;
	}
}

int main(){
	int n;
	cin >> n;
	syc(n,1,20);
	int a[n];
	int count=0,check=0;

	for(int i=0;i<n;i++){
		cin >> a[i];
		syc(a[i],1,100);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(a[j]>a[i]){
				check++;
			}
		}
		if(check==0){
			count++;
		}
		check=0;
	}
	cout << count << endl;
	return 0;
}

#include "bits/stdc++.h"
#define rep(i,a,n) for(int (i) = (a);(i) < (n);(i)++)

using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	
	int n,memo = 0,d[300000];
	cin >> n;
	
	rep(i,0,n){
		cin >> d[i];
	}
	
	
	
	
	rep(i,0,n){
		if(i == 0){
			memo = d[i];
		}
		else{
			memo = max(memo-10,d[i]);
		}
		
		if(memo < 10){
			cout << "no" << endl;
			return 0;
		}
	}
	
	rep(i,0,n){
		if(i == 0){
			memo = d[n-1];
		}
		else{
			memo = max(memo-10,d[n-i-1]);
		}
		
		if(memo < 10){
			cout << "no" << endl;
			return 0;
		}
	}
	
	cout << "yes" << endl;
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std ;
#define m 1000000007
int main (){
	long long int n ; cin >> n ;
	long long int a[n];
	long long int sum =0;
	for(int i = 0;i < n; i ++){
		cin >> a[i];
	}
	long long int suff[n];
	for(long long int  i = n-1, suffs =0  ; i >=0;i--){
		suffs = (suffs+a[i])%m;
		suff[i] = suffs;
	}
	for(int i =0 ;i<n-1;i++){
		sum = (sum + a[i]*(suff[i+1]%m))%m;
	}
	cout <<  sum ;
}

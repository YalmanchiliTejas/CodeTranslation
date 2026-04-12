#include <bits/stdc++.h>
#define max 1000000007
using namespace std ;
int main (){
long long int n ; cin >> n ;
	int a[n];
 long long int suff[n];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
		for(long long int j = n -1, sufff = 0;j>=0;j--){
			sufff = (sufff+ a[j]) % max;
		suff[j] = sufff;
	}
	long long int sum = 0;
		for( int j = 0;j<n-1;j++){
	  sum = (sum + (a[j]*suff[j+1]) % max) % max;
	}
	cout <<  sum << endl;
}

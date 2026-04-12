#include<bits/stdc++.h>
using namespace std;

int n, k;
long long s;

int main(){
	
	cin >> n >> k ;
	
	for( int i = k + 1 ; i <= n ; i++ ){
		s += ( n / i ) * ( i - k );
		if( n % i == 0 ) continue;
		if( n % i > k - 1 ) s += ( n % i ) - (k - 1);
		if( k == 0 ) s--;	
	} 
	
	cout << s << endl;
	
}
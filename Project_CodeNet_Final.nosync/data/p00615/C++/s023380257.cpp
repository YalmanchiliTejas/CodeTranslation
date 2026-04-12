#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std ;

int main(){
	
	int n , m ;
	int s[20002] = {} ;
	int max ;
	
	while(1){
		cin >> n >> m ;
		if( n==0 && m==0 ) break ;
		
		for( int i=0 ; i<n ; i++ ) cin >> s[i] ;
		for( int i=n ; i<n+m ; i++ ) cin >> s[i] ;
		
		sort( s , s+n+m ) ;
		max = s[0] ;
		
		for( int i=0 ; i<n+m-1 ; i++ ){
			if( max < abs( s[i]-s[i+1] ) ) max = abs( s[i]-s[i+1] ) ;
		}
		
		cout << max << endl ;
	}
	
return 0;
}
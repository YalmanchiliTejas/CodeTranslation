#include<bits/stdc++.h>
using namespace std ;

main(){
	string t[21] , tmp ;
	int p[21] , tmp2 ;
	int n , a , b , c ;
	bool r = false ;
	
	while( cin >> n , n ){
		if( r ) cout << endl ;
		r = true ;
		
		map<string,int> x ;
		for( int i=0 ; i<n ; i++ ){
			cin >> t[i] >> a >> b >> c ;
			p[i] = a*3 + c ;
			x[t[i]] = i ;
		}
		
		for( int i=0 ; i<n ; i++ ){
			for( int j=i+1 ; j<n ; j++ ){
				if( p[i] < p[j] || p[i] == p[j] && x[t[i]] > x[t[j]] ){
					tmp = t[i] ;
					t[i] = t[j] ;
					t[j] = tmp ;
					
					tmp2 = p[i] ;
					p[i] = p[j] ;
					p[j] = tmp2 ;
				}
			}
		}
		
		for( int i=0 ; i<n ; i++ ) cout << t[i] << ',' << p[i] << endl ;
	}
}
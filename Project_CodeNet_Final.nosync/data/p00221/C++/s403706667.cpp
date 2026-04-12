#include<iostream>
#include<string>
using namespace std ;

string f( int d ){
	int q , x = 1 ;
	for( q=0 ; d/x ; q++ ) x*=10 ;
	x /= 10 ;
	string b ;
	for( int k=0 ; k<q ; k++ ){
		b += d/x + '0' ;
		d -= d/x * x ;
		x /= 10 ;
	}
	return b ;
}

main(){
	int m,n ;
	while( cin >> n >> m , n ){
		int table[10010] = {} , pre[10010] = {} , nxt[10010] = {} ;
		for( int i=1 ; i<=n ; i++ ){
			table[i] = i ;
			pre[i] = i-1 ;
			nxt[i] = i+1 ;
		}
		pre[1] = n ;
		nxt[n] = 1 ;
		
		int cnt = n-1 , pos = 1 ;
		string s ;
		for( int i=1 ; i<=m ; i++ ){
			cin >> s ;
			if( !cnt ) continue ;
			
			string num = f(i) ;
			if( !(i%15) ) num = "FizzBuzz" ;
			else if( !(i%5) ) num = "Buzz" ;
			else if( !(i%3) ) num = "Fizz" ;
			
			if( s != num ){
				nxt[pre[pos]] = nxt[pos] ;
				pre[nxt[pos]] = pre[pos] ;
				table[pos] = 0 ;
				cnt-- ;
			}
			pos = nxt[pos] ;
		}
		
		bool t = false ;
		for( int i=1 ; i<=n ; i++ ){
			if( table[i] ){
				if( t ) cout << ' ' ;
				cout << i ;
				t = true ;
			}
		}
		cout << endl ;
		
	}
}
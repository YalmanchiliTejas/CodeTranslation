#include<iostream>
#include<string>
using namespace std ;

string s ;
char t[] = {'y','u','i','o','p','h','j','k','l','n','m'} ;

int main(){
	
	while( cin >> s ){
		if( s[0] == '#' ) break ;
		
		int ans = 0 ;
		int x,j ;
		for( int i=0 ; i<s.size() ; i++ ){
			for( j=0 ; j<12 ; j++ ){
				if( s[i] == t[j] ) break ;
			}
			if( i==0 ){
				if( j==12 ) x = -1 ;
				else x = 1 ;
			}else{
				if( j==12 && x==1 ){
					ans++ ;
					x = -1 ;
				}
				else if( j!=12 && x==-1  ){
					ans++ ;
					x = 1 ;
				}
			}
		}
		cout << ans << endl ;
	}
	
return 0;
}
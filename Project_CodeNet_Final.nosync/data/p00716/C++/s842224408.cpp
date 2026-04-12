#include<iostream>
using namespace std ;

int main(){
	
	int m ;
	int capital , year , n ;
	int s , t ;
	double r ;
	
	int max , keep , money ;
	
	cin >> m ;
	
	for( int i=0 ; i<m ; i++ ){
		cin >> capital >> year ;
		cin >> n ;
		max = 0 ;
		for( int j=0 ; j<n ; j++ ){
			cin >> s ;
			cin >> r >> t ;
			
			money = capital ;
			keep = 0 ;
			
			for( int k=0 ; k<year ; k++ ){
				if( s==1 ) money += money * r - t ;
				else {
					keep += money * r ;
					money -= t ;
				}
			}
			
			if( max < money + keep ) max = money + keep ;
		}
		
		cout << max << endl ;
	}
	
	
	
return 0;
}
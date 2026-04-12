#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std ;

typedef pair<int,int> P ;
#define F first
#define S second

vector<P> VC ;
map<int,int> MP;

int main(){
	
	int N,M;
	char p;
	
	while( cin >> N >> p >> M ){
		if( !N && !M ) break ;
		VC.push_back( P(N,M) );
	}
	
	for( int i=0 ; i<VC.size() ; i++ ){
		for( int j=i+1 ; j<VC.size() ; j++ ){
			if( VC[i].S < VC[j].S ) swap(VC[i],VC[j]);
			else if( (VC[i].S == VC[j].S) && (VC[i].F > VC[j].F) ) swap(VC[i],VC[j]);
		}
	}
	
	int cnt = 0;
	int pnt = -1;
	for( int i=0 ; i<VC.size() ; i++ ){
		if( pnt != VC[i].S ){
			pnt = VC[i].S;
			cnt++;
		}
		MP[VC[i].F] = cnt;
	}
	
	while( cin >> N ){
		if( cin.eof() ) break ;
		cout << MP[N] << endl ;
	}
	
	return 0 ;
}
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void output(int y,int m,int d){
	if( y < 10 )
		cout << "000";
	else if( y < 100 )
		cout << "00";
	else if( y < 1000 )
		cout << "0";
	cout << y << " ";
	if( m < 10 )
		cout << "0";
	cout << m << " ";
	if( d < 10 )
		cout << "0";
	cout << d << endl;
}

int main(){
	int n,y,m,d;
	
	while( cin >> n , n ){
		vector<int> vc;

		for(int i=0 ; i<n ; i++ ){
			cin >> y >> m >> d;
			vc.push_back( y*10000 + m*100 + d );
		}
		sort( vc.begin() , vc.end() );
		for(int i=0 ; i<(int)vc.size() ; i++ ){
			y = vc[i] / 10000;
			m = (vc[i]%10000) / 100;
			d = vc[i]%100;
			output( y , m , d );
		}
	}
}
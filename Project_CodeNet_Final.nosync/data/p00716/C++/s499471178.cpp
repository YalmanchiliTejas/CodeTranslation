#include <iostream>
using namespace std;
int main(){
	int m;
	cin >> m;
	while( m-- > 0 ){
		int money, year, n;
		cin >> money >> year >> n;
		int Max = 0;
		while( n-- > 0 ){
			int type, commi;
			double rate;
			cin >> type >> rate >> commi;
			int m1 = money, m2 = 0;
			for( int i = 0; i < year; i++ ){
				if( type == 0 ){
					m2 += m1 * rate;
				}else{
					m1 += m1 * rate;
				}
				m1 -= commi;
			}
			m1 += m2;
			if( Max < m1 ) Max = m1;
		}
		cout << Max << endl;
	}
}
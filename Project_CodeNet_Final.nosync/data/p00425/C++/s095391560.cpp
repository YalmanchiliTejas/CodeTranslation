#include<iostream>
#include<string>
using namespace std;

int main(){
	int up, front, side, sum, n;
	string com;
	while(1){
		cin >> n;
		if( n == 0 )	break;
		up = 1;
		front = 2;
		side = 3;
		sum = 1;
		for( int i=0; i<n; i++ ){
			cin >> com;
			int nup, nfront, nside;
			if( com == "North" ){
				nup = front;
				nfront = 7 - up;
				nside = side;
			}else if( com == "East" ){
				nup = 7 - side;
				nfront = front;
				nside = up;
			}else if( com == "South" ){
				nup = 7 - front;
				nfront = up;
				nside = side;
			}else if( com == "West" ){
				nup = side;
				nfront = front;
				nside = 7 - up;
			}else if( com == "Right" ){
				nup = up;
				nfront = side;
				nside = 7 - front;
			}else if( com == "Left" ){
				nup = up;
				nfront = 7 - side;
				nside = front;
			}
			up = nup;
			front = nfront;
			side = nside;
			sum += up;
		}
		cout << sum << endl;
	}
	return 0;
}
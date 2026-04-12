#include <iostream>
using namespace std ;

int main(){
	bool a,b ;
	a = b = false ;
	char c ;
	for(int i=0;i<3;i++){
		cin >> c ;
		if(c=='A') a = true ;
		else b = true ;
	}
	if(a&&b) cout << "Yes" << endl ;
	else cout << "No" << endl ;
}

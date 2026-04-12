#include <iostream>
#include <vector>
using namespace std ;

int main(){
	int n ; cin >> n ;
	bool ok = true ;
	vector<int> d(n) ;
	for(int i=0;i<n;i++) cin >> d.at(i) ;
	int pos = 0 ;
	for(int i=0;i<n;i++){
		if(i>pos){
			cout << "no" << endl ;
			return 0 ;
		}
		if(pos<i+d.at(i)/10) pos = i+d.at(i)/10 ;
	}
	pos = n-1 ;
	for(int i=n-1;i>=0;i--){
		if(i<pos){
			cout << "no" << endl ;
			return 0 ;
		}
		if(pos>i-d.at(i)/10) pos = i-d.at(i)/10 ;
	}
	cout << "yes" << endl ;
}


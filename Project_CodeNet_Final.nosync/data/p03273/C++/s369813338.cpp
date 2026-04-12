#include <iostream>
#include <vector>
using namespace std ;
using vc = vector<char> ;
using vcc = vector<vc> ;

int main(){
	int h,w ;
	cin >> h >> w ;
	vcc a(h,vc(w)) ;
	int cnt ;
	for(int i=0;i<h;i++){
		cnt = 0 ;
		for(int j=0;j<w;j++){
			cin >> a.at(i).at(j) ;
			if(a.at(i).at(j)=='#') cnt++ ;
		}
		if(cnt==0){
			for(int j=0;j<w;j++){
				a.at(i).at(j) = 'x' ;
			}
		}
	}
	for(int j=0;j<w;j++){
		cnt = 0 ;
		for(int i=0;i<h;i++){
			if(a.at(i).at(j)=='#') cnt++ ;
		}
		if(cnt==0){
			for(int i=0;i<h;i++){
				a.at(i).at(j) = 'x' ;
			}
		}
	}
	for(int i=0;i<h;i++){
		bool ok = false ;
		for(int j=0;j<w;j++){
			if(a.at(i).at(j)=='x') continue ;
			cout << a.at(i).at(j) ;
			ok = true ;
		}
		if(!ok) continue ;
		cout << endl ;
	}
}

#include<iostream>
using namespace std ;

int main(){
	int n,h ; cin >> n ;
	int mx = 0 ;
	int cnt = 0 ;
	for(int i=0;i<n;i++){
		cin >> h ;
		if(mx<=h){
			cnt++ ;
			mx = h ;
		}
	}
	cout << cnt << endl ;
}
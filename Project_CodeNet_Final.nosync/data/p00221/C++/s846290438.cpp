#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string i_to_s(int n){
	string s;
	do{
		s.push_back( (n%10)+'0' );
		n /= 10;
	}while( n != 0 );
	reverse( s.begin() , s.end() );
	return s;
}

string FizzBuzz(int i){
	return i%3?i%5? i_to_s(i):"Buzz":i%5?"Fizz":"FizzBuzz";
}

int main(){
	int m, n;
	int p[1001];
	
	while( cin >> m >> n , m|n ){
		int num = m;
		bool flag = true;
		for(int i=0 ; i<1001 ; ++i )
			p[i] = 1;
		
		for(int i=0, j=0 ; i<n ; ++i , ++j, j%=m ){

			while( p[j] == 0 && flag ){
				j++;
				j %= m;
			}
			string s;
			cin >> s;

			if( !(s == FizzBuzz(i+1)) && flag ){
				p[j] = 0;
				num--;
			}
			if(num==1){
				flag = false;
			}
		}
		vector<int> vc;
		for(int i=0 ; i<m ; ++i ){
			
			if( p[i] )
				vc.push_back( i+1 );
		}
		for(int i=0 ; i<(int)vc.size() ; ++i){
			cout << vc[i];
			(i==vc.size()-1)? cout << endl : cout << " ";
		}

	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N;
  	cin >> N;
  
  	vector<int> H(N);
  	for ( int i = 0 ; i < N ; i++ ){
      cin >> H.at(i);
    }
  
  	int count = 0;
  	for ( int i = N-1 ; i > 0 ; i-- ){
      	for ( int j = i-1 ; j >= 0 ; j-- ){
    		if( H.at(i) - H.at(j) < 0 ){
          		count++;
              	break;}
        }
    }  
  	cout << N - count << endl;
}
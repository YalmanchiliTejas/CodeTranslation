#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 
int main(void){
    
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
    			cin >> A.at(i);
  	}
  	
  	int counter =0; // 今までBに書き込まれたマス目の数
  	vector<ll> B(N);
  	
  	for(int i=0; i<N; i++){
  	    if( i ==0 ){
  	        B.at(0)= A.at(0);
  	        counter =1; 
  	    }else if(B.at(counter-1) >= A.at(i) ){
  	           B.at(counter) = A.at(i); 
  	           counter++; 
  	    }else{
  	    // メインループ    
  	      int a = A.at(i); 
  	      int left = 0;
  	      int right = counter-1; 
  	      while(right - left > 1){
  	        int pointer = (left + right)/2;
  	        if( a > B.at(pointer) ){
  	            right = pointer; 
  	        }else{
  	            left = pointer; 
  	        } 
  	      }
  	      if(a>B.at(0)){
  	          B.at(0) = a;
  	      }else{
  	        B.at(right) = a;
  	      }
  	    }
  	    
  	}
  	
/*  	for(int i=0; i<N; i++){
  	    cout<< B.at(i) << endl; 
  	}
*/
  	cout<< counter << endl; 

}
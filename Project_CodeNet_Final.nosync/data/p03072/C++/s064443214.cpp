#include<iostream>

#include <math.h>
using namespace std;

typedef  long long ll;

int main(){
	
  	int N;
  	cin >> N;
  	int H,min;
  	int cont = 0;
  	for(int i = 0; i< N ;i++){
      	cin >> H;
      	if(i==0)min = H;
  		if(min<=H){
        	cont++;
        	min = H;
        }

    }
  cout << cont << endl;
  
}
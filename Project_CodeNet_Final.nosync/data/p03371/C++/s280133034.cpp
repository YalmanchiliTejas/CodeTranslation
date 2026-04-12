#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;



int main(){

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
 
	int res = A*X + B*Y;
  	for(int i=1; i<= max(X, Y); i++){
    	int ab = i*2;
      	int cand = C*ab + A*max(X-i, 0) +B*max(Y-i, 0);
      	res = min(res, cand);
    }
  
  cout << res << endl;
  return 0;
  
}

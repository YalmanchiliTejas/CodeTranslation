#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,i,H;
  H=0;
  i=0;
  cin >> N ;
	while(cin >>M){
    if(H <=M){
    	H=M;
      i+=1;
    }
    }
 cout << i << endl;
}


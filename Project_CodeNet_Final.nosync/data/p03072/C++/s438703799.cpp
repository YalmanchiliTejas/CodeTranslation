#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  	int N=0,i=0,j=0,rs=1;
  	bool f = true;
  	
  	cin >> N;
  	int H[N]={};
  	for(i=0;i<N;i++){
    	cin >> H[i];
    }
    for(i=1;i<N;i++){
      f=true;
 		for(j=i-1;j>=0;j--){
          if((H[i] - H[j])<0){
            f = false;
            break;
          }
        }
      if(f){
        rs++;
      }
    }
  cout << rs <<endl;
  	
	return 0;
}
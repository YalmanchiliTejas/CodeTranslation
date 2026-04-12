#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
	int N, res = 0, max = 0;
  	cin >> N;
  	vector<int> H(N);
  	for(int i = 0; i < N; i++){
    	cin >> H[i];
    }
  
  	for(int i = 0; i < N; i++){
    	if(H[i] >= max){
          	max = H[i];
        	res++;
        }
    }
  	
  	cout << res << endl;
  	
	return 0;
}
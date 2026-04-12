#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int H[N];
  for(int i = 0; i < N; i++){
  	cin >> H[i];
  }
  int count = 0;
  for(int i = 1; i <= N-1; i++){
  	for(int j = 0; j < i; j++){
    	if(H[j] > H[i]){
        	break;
        }
      	if(j+1 == i){
        	count++;
        }
    }
  }
  
  cout << count+1 << endl;
}
#include <iostream>
using namespace std;
int main(){
	int N;
  cin >> N;
  int height[N];
  for(int i = 0;i<N;i++){
  	cin >> height[i];  }
  int max=0;
  int counter=0;
  for(int k=0;k<N;k++){
	if(max<=height[k]){
    	max = height[k];
 
      ++counter; 
    } 	
  }
  cout << counter <<endl;
  return 0;
}

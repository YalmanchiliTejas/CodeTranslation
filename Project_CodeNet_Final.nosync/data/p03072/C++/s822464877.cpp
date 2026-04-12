#include <iostream>
 
int main(void){
	int result = 0;
  	int N;
  	std::cin >> N;
  
  	int* array = new int[N];
  
  	for(int i = 0; i < N; ++i){
    	std::cin >> array[i];
    }
  
  	int count = N;
  
  	for(int i = N-1; i > 0; --i){
      for(int j = i-1; j >=0; --j){
     	if(array[i] < array[j]){
          --count;
          break;
        }
      }
    }
          
  	std::cout << count;
    delete array;
    return 0;
}
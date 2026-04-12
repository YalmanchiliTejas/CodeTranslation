#include <iostream>
using namespace std;
int main(void){
    unsigned int N, H, max, ret=0;
    
    std::cin >> N >> H;
    max = H;
    ret++;
    
   for(int i=1; i<N; i++) {
       std::cin >> H;
       if(max <= H){
           ret++;
           max = H;
       }
   }
        
    std::cout << ret << std::endl;
    
    return 0;
    
}

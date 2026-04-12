#include <iostream>

int main(){
   int N;
   std::cin >> N;
   int H[N];
   for(int i=0; i<N; ++i)
      std::cin >> H[i];

   int ans = 1;
   for(int i=1; i<N; ++i){
      bool flag = true;
      for(int j=0; j<i; ++j){
	 if(H[j]>H[i]){
	    flag = false;
	    break;
	 }
      }
      if(flag) ++ans;
   }
   std::cout << ans << std::endl;

   return 0;
}

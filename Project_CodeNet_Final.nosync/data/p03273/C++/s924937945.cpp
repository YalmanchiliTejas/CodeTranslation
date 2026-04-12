#include <iostream>
#include <vector>
#include <string>

int main(){
   int H, W;
   std::cin >> H >> W;
   std::vector<std::string> a(H);
   for(int i=0; i<H; ++i){
      std::string tmp;
      std::cin >> tmp;
      a[i] = tmp;
   }

   std::vector<bool> row(H);
   std::vector<bool> column(W);
   for(int i=0; i<H; ++i){
      for(int j=0; j<W; ++j){
	 if(a[i][j] == '#') {
	    row[i] = true;
	    column[j] = true;
	 }
      }
   }
      
   for(int i=0; i<H; ++i){
      if(row[i]){ 
	 for(int j=0; j<W; ++j){
	    if(column[j]){
	       std::cout << a[i][j];
	    }
	 }
	 std::cout << std::endl;
      }
   }

   return 0;
}

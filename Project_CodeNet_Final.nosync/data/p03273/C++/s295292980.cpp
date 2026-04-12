#include <iostream>
#include <vector>

int main(){
   int H, W;
   std::cin >> H >> W;
   std::vector<std::string> a(H);
   for (int i=0; i<H; i++){
      std::cin >> a.at(i);
   }
   std::vector<bool> hflag(H);
   std::vector<bool> wflag(W);
   std::string wd;
   //std::string ws;
   for (int i=0; i<W; i++){
      wd = wd + ".";
      //ws = ws + "#";
   }
   for (int i=0; i<H; i++){
      //if ((a.at(i) == wd) || (a.at(i) == ws)){
      if (a.at(i) == wd){
         hflag.at(i) = true;
      } else{
         hflag.at(i) = false;
      }
   }
   for (int j=0; j<W; j++){
      for (int i=0; i<H; i++){
         if (a.at(i).at(j) == '#'){
            wflag.at(j) = false;
            break;
         } else{
            wflag.at(j) = true;
         }
      }
   }
   for (int i=0; i<H; i++){
      if (hflag.at(i) == true){
         continue;
      }
      else{
         for (int j=0; j<W; j++){
            if (wflag.at(j) == true){
               continue;
            } else{
               std::cout << a.at(i).at(j);
            }
         }
         std::cout << std::endl;
      }
   }
}


#include <iostream>
#include <string>

int main(){
   int n;
   std::string s;
   int k;
   std::cin >> n >> s >> k;
   
   const auto a = s[k-1];
   for(auto& c : s){
      if(c != a){
         c = '*';
      }
   }
   std::cout << s;
}
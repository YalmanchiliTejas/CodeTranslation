//B - Grid Compression
#include <bits/stdc++.h>
using namespace std;

int main() {
   int h, w; cin >> h >> w;
   vector<string> mas;
   for(int i = 0; i < h; i++){
      string line; cin >> line;
      int num = count(line.begin(), line.end(), '.');
      if(num != line.size())
         mas.push_back(line);
   }
   
   for(int i = 0; i < w; i++){
      int count = 0;
      for(int j = 0; j < mas.size(); j++){
         if(mas.at(j).at(i)=='.') count++;
      }
      
      if( count == mas.size() ){
         for(int j = 0; j < mas.size(); j++){
            if(mas.at(j).at(i)=='.') mas.at(j).at(i) = '-';
         } 
      }
   }
   
   for(int i = 0; i < mas.size(); i++){
      for(int j = 0; j < mas.at(i).size(); j++){
         if(mas.at(i).at(j) != '-'){
            cout << mas.at(i).at(j);
         }
      } cout << endl;
   }
}

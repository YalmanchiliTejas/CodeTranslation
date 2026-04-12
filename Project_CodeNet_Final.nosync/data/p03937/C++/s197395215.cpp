#include <iostream>
#include<vector>
using namespace std;
int main(void){
   int h,w;
   cin >> h >> w;
   vector<string> s(h);
   for(int i = 0;i < h;i++){
         cin >> s[i];
   }
   int stone = 0;
   for(int i = 0;i < h;i++){
         for(int j = 0;j < w;j++){
               if(s[i][j] == '#')stone++;
         }
   }
   cout << ((h + w - 1 == stone) ? "Possible" : "Impossible") << endl;
}

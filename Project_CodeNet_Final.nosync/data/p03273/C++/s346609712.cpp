#include <iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
 int H, W, sum = 0, sum2 = 0;
 int i,j;
  
 cin >> H >> W;
 vector<string>s(H);
 for (i = 0;i < H;++i)cin >> s[i];
 
  
 for (i = 0;i < H-sum;++i) {
 int count = 0; 
 for (j = 0;j < W;++j)if (s[i][j] == '.')++count;
 if (count == W) {
   s.erase(s.begin()+i);
   --i;
   ++sum;
  }
 }
 
 for (j = 0;j < W-sum2;++j) {
 int count2 = 0;
 for (i = 0;i < H-sum;++i)if (s[i][j] == '.')++count2;
 if (count2 == H-sum) {
  for (i = 0;i < H-sum;++i)s[i].erase(s[i].begin() + j); 
   --j;
   sum2++;
  }
 }
 
  
 for (int i = 0;i < s.size();++i)cout << s[i] << endl;
 
 return 0;
    
}

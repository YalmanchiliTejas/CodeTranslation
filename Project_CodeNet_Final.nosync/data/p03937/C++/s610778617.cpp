#include<bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> vec.at(i).at(j);
    }
  }
  string ans = "Possible";
  int last = 0;
  for(int k=0; k<H; k++){
    for(int l=0; l<W; l++){
      if((l<last) && (vec.at(k).at(l) == '#')){
        ans = "Impossible";
      }
      if((l>=last) && vec.at(k).at(l) == '.'){
        for(int m=W-1; m>=l-1; m--){
         if(vec.at(k).at(m) == '#' && m == W-1){
           last = W-1;
           break;
          }
         else if(vec.at(k).at(m) == '#'){
         last = max(last,m);
         break;
         }
         else if(m == l+1){
         last = max(last,l-1);
         break;
         }
        }
        break;
      }
      if(l == W-1 && vec.at(k).at(l) == '#'){
        last = W-1;
        break;
      }
    }
  }
  cout << ans << endl;
}     
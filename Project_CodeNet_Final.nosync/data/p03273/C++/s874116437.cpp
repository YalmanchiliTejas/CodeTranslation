#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector <vector <char>> A(H, vector <char>(W));
   for (int i = 0; i < H; ++i) {
   for (int j = 0; j < W; ++j) {
   cin >> A[i][j];
}
}
////////
  vector<int> gyou;
  vector<int> retsu;
  vector<int> copy{0};
  for(int i=0;i<H;++i){
    int count = 0;
    for(int j=0;j<W;++j){
      if(A[i][j]=='.'){
        count += 1;
      }
    }
  if(count == W){gyou.push_back(i);}
  }
 
  for(int j=0;j<W;++j){
    int count = 0;
    for(int i=0;i<H;++i){
      if(A[i][j]=='.'){
        count += 1;
      }
    }
  if(count == H){retsu.push_back(j);}
  }
//////////////
gyou.push_back(10000);
retsu.push_back(10000);
int a =0;
for (int i = 0; i < H; ++i) {
    a=0;
    if(gyou[0]==i){
      gyou.erase(gyou.begin());}
    else{
      for(int j=0;j<W;++j) {
        copy[0] = retsu[a];
        if(copy[0]==j){
          a+=1;
        }
        else{
          cout<<A[i][j];
        }
      }
      cout<<endl;
    }

}
}
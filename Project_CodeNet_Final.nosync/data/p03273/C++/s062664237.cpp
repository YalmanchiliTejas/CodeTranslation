#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int H,W,count,H2,W2;
cin >>H>>W;
H2=H;
W2=W;
vector<vector<char>> table(H,vector<char>(W)); 
rep(i,H){
rep(j,W){
  cin>>table[i][j];

}

}
rep(i,H){
  count=0;
rep(j,W){
if(table[i][j]=='.'){
count++;
}
}
if(count==W){
rep(j,W){
  table[i][j]='0';

}
H2--;
}
  
}
rep(j,W){
  count=0;
rep(i,H){
  if(table[i][j]=='.'){
  count++;
  }

}
if(count==H2){
rep(i,H){
table[i][j]='0';
}
W2 = min(W2,j);
}
else{
    W2 = max(W2,j);
}
}
rep(i,H){
rep(j,W){
  if(table[i][j]=='0'){
 
  }
    
  
  else{
    cout<<table[i][j];
  if(j==min(W2,W-1)){
  cout<<endl;
  }
    
  }
}

}

}

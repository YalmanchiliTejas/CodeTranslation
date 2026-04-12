#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  for(int i = 0;i<n;i++){
    cin >> S[i];
  }
  vector<char> C;
  for(char c = 'a';c<='z';c++){
   int x = 0;//ある文字がS[i]に含まれているか
   for(int i = 0;i<n;i++){
      for(int j = 0;j<S[i].size();j++){
      if(S[i][j] == c){
        x++;
        break;
      }
     }
     if(x == n){//ある文字がすべてのS[i]に含まれていればその文字をCに追加
      C.push_back(c);
   }
  }
 }   

  vector<pair<char,int>> p(C.size());
   for(int i = 0;i<C.size();i++){
     p[i].first = C[i];
   }
  
 if(p.size()>=1){ 
  for(int i = 0;i<p.size();i++){
   vector<int> min(n);//共通文字の個数の配列
   int count = 0;//共通文字の個数
   for(int j = 0;j<n;j++){
    for(int k = 0;k<S[j].size();k++){
      if(S[j][k] == p[i].first) count++;
    }
     min[j] = count;
     count = 0;
   }
    sort(min.begin(),min.end());
    p[i].second = min[0];
  }

  string ANS;
  for(int i = 0;i<p.size();i++){
    for(int j = 0;j<p[i].second;j++){
      ANS = ANS +p[i].first;
    }
  }
  cout << ANS << endl;
 }
  else return 0;
}
#include <iostream>
#include <map>
using namespace std;
int main(){
  char T;
  map<char,int> M;
  for(int i = 2; i < 10; ++i) M['0'+i] = i;
  M['T'] = 10;
  M['J'] = 11;
  M['Q'] = 12;
  M['K'] = 13;
  M['A'] = 14;
  while(cin >> T, T != '#'){
    string C[4][13];
    for(int i = 0; i < 4; ++i)
      for(int j = 0; j < 13; ++j)
        cin >> C[i][j];
    int score[] = {0,0};
    int t = 0;
    for(int i = 0; i < 13; ++i){
      bool f = false;
      int t_ = t, m = M[C[t][i][0]];
      char s = C[t][i][1];
      for(int j = 0; j < 4; ++j){
        int j_ = (t + j)%4;
        if(f){
          if(M[C[j_][i][0]] > m && C[j_][i][1] == T){
            t_ = j_;
            m = M[C[t_][i][0]];
          }
        }else{
          if(C[j_][i][1] == T){
            t_ = j_;
            m = M[C[j_][i][0]];
            f = true;
          }else if(M[C[j_][i][0]] > m &&  C[j_][i][1] == s){
            t_ = j_;
            m = M[C[j_][i][0]];
          }
        }
      }
      t = t_;
      ++score[t%2];
    }
    if(score[0] > score[1]) cout << "NS " << score[0] - 6 << endl;
    else cout << "EW " << score[1] - 6 << endl;
  }
  return 0;
}


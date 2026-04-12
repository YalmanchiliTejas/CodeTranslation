#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0;i<N;i++){
    cin >> S.at(i);
    sort(S.at(i).begin(),S.at(i).end());
  }
  vector<char> A(0);
  for(int i=0;i<S.at(0).size();i++){//S0の第i文字が他全てのSに入ってるならAに追加
    char x = S.at(0).at(i);
    bool all = true;
    for(int j=1;j<N;j++){//Sjにxが入ってますか？
      bool exist = false;
      for(int k=0;k<S.at(j).size();k++){//Sjの各要素を調べる
        if(S.at(j).at(k) == x){
          S.at(j).at(k) = '0';
          exist = true;
          break;
        }
      }
      if(exist){
      }else{
        all = false;
        break;
      }
    }
    if(all){
      A.push_back(x);
    }
  }
  for(int i=0;i<A.size();i++){
    cout << A.at(i);
  }
  cout << endl;
}
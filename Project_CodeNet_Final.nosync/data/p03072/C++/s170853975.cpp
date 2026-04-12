#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>H(N);
  for (int i=0; i < N; i++) {
   cin >> H.at(i);//i番目の山の高さ
  }
  int f =1;//眺められる数（最西端は確定だから初期値は１
  int c =H.at(0);//最初は最西端が高さmax
  for(int i=1;i<N;i++){
    if(c<=H.at(i)){//i番目の山がmaxより高い場合
      f++;//眺＋１
      c = H.at(i);//max更新
    }
  }
    cout<< f << endl;
}
 
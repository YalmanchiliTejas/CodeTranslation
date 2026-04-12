#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> x, sx;

int main(){
  cin >> N;
  
  int v;
  for(int i = 0; i < N; i++){ cin >> v;  x.push_back(v); sx.push_back(v); }
  sort(sx.begin(), sx.end());

  for(int i = 0; i < N; i++){
    if(sx[N/2] > x[i]) cout << sx[N/2] << endl;     //削除場所が中央値かそれより左ならずれる
    else cout << sx[N/2-1] << endl;                          //右ならずれない
  }

  return 0;
}
    

 
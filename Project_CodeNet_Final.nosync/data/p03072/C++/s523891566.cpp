#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0;i<N;i++){
    cin >> H.at(i);
  }
  int S=1;
  for (int j=1;j<N;j++){
    int s=1;
    for (int i=0;i<j;i++){
      if (H.at(j)>=H.at(i)){
        s*=1;
      }
      else {
        s*=0;
      }
    }
    if (s==1){
      S+=1;
    }
    else {
      S=S;
    }
  }
  cout << S << endl;
}

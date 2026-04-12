#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int Ans=0;
  int Max=0;
  int H;
  for(int i=0; i<N; i++){
    cin >> H;
    if(H>=Max){
      Ans++;
      Max=H;
    }
  }
  cout << Ans << endl;
}
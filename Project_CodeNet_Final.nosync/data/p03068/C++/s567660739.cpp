#include <bits/stdc++.h>
using namespace std;



int main(){
  int a;
  cin >> a;
  char b[a];
  for(int i = 0;i < a;i++){
    cin >> b[i];
  }
  int d;
  cin >> d;
  char c = b[d-1];
  string answer = "";
  for(int i = 0;i < a;i++){
    if(b[i] != c){
      b[i] = '*';
    }
    answer += b[i];
  }
  cout << answer << endl;

}

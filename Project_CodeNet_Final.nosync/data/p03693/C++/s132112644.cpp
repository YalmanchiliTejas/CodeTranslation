#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if((C+B*10)%4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" <<endl;
  }
}
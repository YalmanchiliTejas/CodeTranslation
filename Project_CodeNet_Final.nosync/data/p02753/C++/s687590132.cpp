#include <bits/stdc++.h>
using namespace std;

int main(){
  bool flaga = false, flagb = false;
  for(int i = 0; i < 3; i++){
    char a;
    cin >> a;
    if(a == 'A') flaga = true;
    if(a == 'B') flagb = true;
  }
  if(flaga && flagb){
    cout << "Yes" <<endl;
  }else{
    cout << "No" <<endl;
  }
}

    
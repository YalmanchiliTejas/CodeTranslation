#include<bits/stdc++.h>

using namespace std;

int main()
{
  while(1){
    string AC;
    cin>>AC;

    if(AC == "#"){
      break;
    }

    int count = 0;
    int i = 0;
    for(char e : AC){
      if(i == 0){
        if(e == 'y' || e == 'u' || e == 'i' || e == 'o' || e == 'p' || e == 'h' || e == 'j' || e == 'k' || e == 'l' || e == 'n' || e == 'm'){
          i = 2;
        }
        else{
          i = 1;
        }
      }
      else if(i == 1){
        if(e == 'y' || e == 'u' || e == 'i' || e == 'o' || e == 'p' || e == 'h' || e == 'j' || e == 'k' || e == 'l' || e == 'n' || e == 'm'){
          i = 2;
          ++count;
        }
        else{
          continue;
        }
      }
      else{
        if(e == 'y' || e == 'u' || e == 'i' || e == 'o' || e == 'p' || e == 'h' || e == 'j' || e == 'k' || e == 'l' || e == 'n' || e == 'm'){
          continue;
        }
        else{
          i = 1;
          ++count;
        }
      }
    }

    cout<<count<<endl;
  }

  return 0;
}

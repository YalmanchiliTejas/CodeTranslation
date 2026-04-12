#include <iostream>

using namespace std;

int main(){
  int H,W;
  cin >> H;
  cin >> W;
  char data[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> data[i][j];
    }
  }

  for(int i=0;i<H;i++){
    bool flag = true;
    for(int j=0;j<W;j++){
      if(data[i][j]=='#'){
        flag = false;
      }
    }

    if(flag == true){
      for(int j=0;j<W;j++){
        data[i][j]='0';
      }
    }
  }

  for(int j=0;j<W;j++){
    bool flag = true;
    for(int i=0;i<H;i++){
      if(data[i][j]=='#'){
        flag = false;
      }
    }
    if(flag == true){
      for(int i=0;i<H;i++){
        data[i][j]='0';
      }
    }
  }



  for(int i=0;i<H;i++){
    int counter = 0;
    for(int j=0;j<W;j++){
      if(data[i][j]=='0'){
        continue;
      }
      cout << data[i][j];
      counter++;
    }
    if(counter!=0){
      cout << endl;
    }
  }

  return 0;
}
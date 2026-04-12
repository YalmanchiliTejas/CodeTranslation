#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  int a[H][W];
  int rem_h[H];
  int rem_w[W];
  string input;

  for(int h=0; h<H; ++h){
    cin >> input;
    if(input.find("#") != string::npos){
      rem_h[h] = 1;
    }else{
      rem_h[h] = 0;
    }
    for(int w=0; w<W; ++w){
      if(input[w] == '#'){
        a[h][w] = 1;
      }else{
        a[h][w] = 0;
      }
    }
  }

  int sharp;
  for(int w=0; w<W; ++w){
    sharp = 0;
    for(int h=0; h<H; ++h){
      if(a[h][w] == 1){
        ++sharp;
      }
    }
    if(sharp > 0){
      rem_w[w] = 1;
    }else{
      rem_w[w] = 0;
    }
  }

  for(int h=0; h<H; ++h){
    if(rem_h[h] == 0){
      continue;
    }else{
      for(int w=0; w<W; ++w){
        if(rem_w[w] == 0){
          continue;
        }
        if(a[h][w] == 1){
          cout << "#";
        }else{
          cout << ".";
        }
      }
      cout << endl;
    }
  }

  return 0;
}

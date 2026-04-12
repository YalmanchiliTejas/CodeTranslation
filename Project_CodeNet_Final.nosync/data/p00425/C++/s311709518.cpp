#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<random>
using namespace std;

class Dice{
  public:
    vector<int> n;
    int top;
    int sum = 0;
    Dice(){
      n.resize(6);
      for(int i=0; i<6; i++) n[i] = i+1;
      top = 0;
    }
    void roll(char c){
      int tmp = n[0];
      if( c == 'E' ){
        n[0] = n[3];
        n[3] = n[5];
        n[5] = n[2];
        n[2] = tmp;
      }else if( c == 'W' ){
        n[0] = n[2];
        n[2] = n[5];
        n[5] = n[3];
        n[3] = tmp;
      }else if( c == 'N' ){
        n[0] = n[1];
        n[1] = n[5];
        n[5] = n[4];
        n[4] = tmp;
      }else if( c == 'S' ){
        n[0] = n[4];
        n[4] = n[5];
        n[5] = n[1];
        n[1] = tmp;
      }else if( c == 'R' ){
        tmp = n[4];
        n[4] = n[3];
        n[3] = n[1];
        n[1] = n[2];
        n[2] = tmp;
      }else if( c == 'L' ){
        tmp = n[4];
        n[4] = n[2];
        n[2] = n[1];
        n[1] = n[3];
        n[3] = tmp;
      }
      sum += n[0];
    }
    void input(){
      for(int i=0; i<6; i++) cin >> n[i];
    }

    void output_top(){
      cout << n[top] << endl;
    }
    void output_sum(){
      cout << sum << endl;
    }
};

bool diff_check(Dice d, Dice d2){
  random_device rnd;
  string con = "NSEW";

  int cnt = 0;
  while(true){
    if( cnt >= 1000 ) break;
    d2.roll( con[rnd()%4] );
    if( d.n[0] == d2.n[0] ){
      if( d.n[5] != d2.n[5] ) break;

      for(int i=0; i<4; i++){
        d2.roll('R');
        bool f = true;
        for(int i=1; i<5; i++){
          if( d.n[i] != d2.n[i] ) f = false;
        }
        if( f ){
          return true;;
        }
      }

      break;
    }
    cnt++;
  }
  return false;
}

int main(){
  random_device rnd;
  string con = "NSEW";

  // d.input();

  int n;
  while(cin >> n){
    if( n == 0 ) break;
    Dice d;

    d.sum += d.n[0];

    for(int i=0; i<n; i++){
      string s;
      cin >> s;
      d.roll(s[0]);
    }

    d.output_sum();
  }

  // d.output_top();

  return 0;
}





// EOF
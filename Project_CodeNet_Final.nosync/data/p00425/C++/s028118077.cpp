#include<iostream>
#include<string>

using namespace std;

void Run1(int&, int&, int&, int&, int&);
void Run2(int&, int&, int&, int&, int&, int&);
void Spin(int&, int&, int&, int&);

int main(){
  int i, n, sum, up, down, north, south, west, east;
  string str;

  while(1){
    cin >> n;
    if(n == 0) break;

    sum = 1;
    up = 1;
    down = 6;
    south = 2;
    north = 5;
    east = 3;
    west = 4;

    for(i=0; i<n; ++i){
      cin >> str;

      if(str == "South")
        Run1(sum, up, north, down, south);
      else if(str == "North")
        Run1(sum, up, south, down, north);
      else if(str == "East")
        Run1(sum, up, west, down, east);
      else if(str == "West")
        Run1(sum, up, east, down, west);
      else if(str == "Right")
        Run2(sum, up, south, east, north, west);
      else if(str == "Left")
        Run2(sum, up, south, west, north, east);
    }

    cout << sum << endl;
  }

  return 0;
}

void Run1(int& sum, int& a, int& b, int& c, int& d){
  Spin(a, b, c, d);
  sum += a;
}

void Run2(int& sum, int& up, int& a, int& b, int& c, int& d){
  Spin(a, b, c, d);  
  sum += up;
}

void Spin(int& a, int& b, int& c, int& d){
  int e;
  e = a;
  a = b;
  b = c;
  c = d;
  d = e;
}
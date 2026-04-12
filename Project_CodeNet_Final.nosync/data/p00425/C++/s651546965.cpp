#include <iostream>
using namespace std;

void turn(int &a, int &b){
  int tmp=a; a=b; b=7-tmp;
}

int main(){
  int n, sum;
  string s;
  int top, front, right, tmp;
  while( cin>>n && n ){
    sum=1;
    top=1; front=2; right=3;
    while( n-- ){
      cin >> s;
      switch( s[0] ){
      case 'N': turn( top, front ); break;
      case 'S': turn( front, top ); break;
      case 'W': turn( top, right ); break;
      case 'E': turn( right, top ); break;
      case 'R': turn( front, right ); break;
      case 'L': turn( right, front ); break;
      }
      sum += top;
    }
    cout << sum << endl;
  }
  return 0;
}
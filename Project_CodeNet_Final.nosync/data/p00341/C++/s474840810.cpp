#include <iostream>
using namespace std;

int numberoftimes(int n[12],int x,int *y){
  int a = 0;
  int flag = 0;
  for(int i = 0; i < 12; i++ ) {
    if( n[i] == x ){
      a++;
    }else if(flag == 0){
      flag = 1;
      *y = n[i];
    }
  }

  return a;
}

int main(void){
  int n[12];
  int a,b,c,x,y;

  for ( int i = 0; i < 12; i++ ){
    cin >> n[i];
  }

  x = n[0];
  a = numberoftimes(n,x,&y);
  x = y;
  b = numberoftimes(n,x,&y);
  x = y;
  c = numberoftimes(n,x,&y);

  if ( a % 4 == 0 && b % 4 == 0 && c % 4 == 0){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }

  return 0;
}
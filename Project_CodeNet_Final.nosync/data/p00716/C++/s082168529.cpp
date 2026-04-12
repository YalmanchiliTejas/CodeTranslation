#include <iostream>
using namespace std;

int tanri(int init, int year, double rate, int fee ){
  int store=0;
  while( year-- ){
    double rishi = init * rate;
    store += (int)rishi;
    init -= fee;
  }
  return init + store;
}
int hukuri(int init, int year, double rate, int fee ){
  while( year-- ){
    double rishi = init * rate;
    init = init + (int)rishi - fee;
  }
  return init;
}


int main(){
  int m;

  int init, year, n;
  int betu;
  double rate;
  int fee;

  cin >> m;
  while(m--){
    cin >> init >> year >> n;
    int mx=0;
    while( n-- ){
      cin >> betu >> rate >> fee;
      if( betu )
	mx = max( mx, hukuri(init,year,rate,fee) );
      else
	mx = max( mx, tanri(init,year, rate,fee) );
    }
    cout << mx << endl;
  }

  return 0;
}
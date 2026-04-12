#include <iostream>
#include <string>

using namespace std;

int main(void){

  while(1){ 
    int a = 1;//上
    int b = 2;//南
    int c = 3;//東
    string s;
    int n;
    cin >> n;
    if( n == 0 )break;
    int sum = 1;
    for( int i = 0 ; i < n ; i++ ){
     
      cin >> s;

      if( s == "North" ) {
	int temp1 = b;
	b = 7 - a;
	a = temp1;
	sum += a;
      }
      else if( s == "East" ){
	int temp2 = c;
	c = a;
	a = 7 - temp2;
	sum += a;
      }
      else if( s == "West" ){
	int temp3 = c;
	c = 7 - a;
	a = temp3;
	sum += a;
      }
      else if( s == "South" ){
	int temp4 = a;
	a = 7 - b;
	b = temp4;
	sum += a;
      }
      else if( s == "Right" ){
	int temp5 = b;
	b = c;
	c = 7 - temp5;
	sum += a;
      }
      else if( s == "Left" ){
	int temp6 = c;
	c = b;
	b = 7 - temp6;
	sum += a;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
#include <iostream>
using namespace std;

int main(){
  int n, data, max,min;
  int sum;

  while( cin>>n,n ){
    min = 10000, max = -1;
    sum = 0;
    for( int i=0;i<n;i++ ){
      cin >> data;
      if( data>max ) max = data;
      if( data<min ) min = data;
      sum += data;
    }
    sum = sum - max -min;
    cout << sum/(n-2) << endl;
  }

  return 0;
}
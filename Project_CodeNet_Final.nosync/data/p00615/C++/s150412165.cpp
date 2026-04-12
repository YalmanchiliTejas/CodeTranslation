#include <iostream>
#include <algorithm>
using namespace std;
  
int main(void){
  int n,m,max;
  int i,j,k;
  int car[20000];
  
  while(1){
    max=0;
  
    cin >> n >> m;
    if( n == 0 && m == 0 ) break;
  
    for( i = 0 ; i < n ; i++ ){
      cin >> car[i];
    }
  
    for( j = n ; j < n + m ; j++ ){
      cin >> car[j];
    }
  
    sort( car , car + n+m );
  
    for( k = 0 ; k < n + m ; k++ ){
  
      if( max < car[k] - car[k-1] ) max = car[k] - car[k-1];
  
    }
  
    cout << max << endl;
  
  }
  
  return 0;
  
}
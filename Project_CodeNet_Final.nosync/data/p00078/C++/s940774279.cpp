#include <iostream>
#include <cstdio>

using namespace std;

int main(void){

  int n;
  int MS[15][15];

  while( cin >> n ){
    if( n == 0 ) break;

    for( int i = 0 ; i < 15 ; i++ ){
      for( int j = 0 ; j < 15 ; j++ ){
	MS[i][j] = 0;
      }
    }

    MS[n/2+1][n/2] = 1;
    int i,j;
    i = n/2+1;
    j = n/2;

    for( int N = 2 ; N <= n*n ; N++ ){
      i++;
      j++;
      if( i >= n ){
	i = 0;
      }
      if( j >= n ){
	j = 0;
      }
      if( MS[i][j] > 0 ){
	i++;
	j--;
	if( j < 0 ){
	  j = n - 1;
	}
	if( i >= n ){
	  i = 0;
	}
      }
      MS[i][j] = N;
    }

    for( int i = 0 ; i < n ; i++ ){
      for( int j = 0 ; j < n ; j++ ){
	printf("%4d",MS[i][j]);
      }
      cout << endl;
    }
  }

  return 0;
}
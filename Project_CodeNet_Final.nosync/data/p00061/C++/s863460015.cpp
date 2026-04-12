#include <iostream>

using namespace std;

int num[2020];
int cor[2020];
int rank[2020];

void bubble_sort(int n){

  for( int i = 0 ; i < n - 1 ; i++ ){
    for( int j = n - 1 ; j > i ; j-- ){
      
      if( cor[j-1] < cor[j] ){
	int temp = cor[j-1];
	cor[j-1] = cor[j];
	cor[j] = temp;

	temp = num[j-1];
	num[j-1] = num[j];
	num[j] = temp;
      }
    }
  }


}

int main(void){

  char ten;
  int cnt = 0;
  for( int i = 0 ; i < 2020 ; i++ ){
    cin >> num[i] >> ten >> cor[i];
    if( num[i] == cor[i] && cor[i] == 0 )break;
    cnt++;
  }
  bubble_sort(cnt);


  int n;
  int I = 1;

  for( int i = 0 ; i < cnt ; i++ ){
    if( cor[i] == cor[i+1] ){
      rank[i] = rank[i+1] = I;
      continue;
    }
    else{
      rank[i] = I;
      I++;
    }
  }
  //   for( int i = 0 ; i < cnt ; i++ )cout << num[i] << "-" << cor[i] << "--" << rank[i] << endl;
  while( cin >> n ){
    for( int i = 0 ; i < 2020 ; i++ ){
      if( n == num[i] ){
	cout << rank[i] << endl;
	break;
      }
    }
  }
  return 0;
}
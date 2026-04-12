#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int N;
  int i, j;
  int count = 1;
  int flag;
  cin >> N ;
  vector<int> H(N);

  for(i=0; i<N; i++)
    cin >> H[i];

  for(i=1; i<N; i++){
    flag = 1;
    for(j=0; j<i; j++)
      if(H[j] > H[i]){
	flag = 0;
	break;
      }
    if(flag == 1)
      count++;
  }

  cout << count << endl;

  return 0;
}

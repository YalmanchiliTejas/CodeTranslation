#include <iostream>
#include <stdlib.h>
using namespace std;
int N, S;
int main()
{
  while (cin >> N && N > 0){
    if (N<3 || N>100)
      exit (1);
    int sum = 0;
    int largest = 0;
    int smallest =1000;
    for (int i=0; i<N; ++i){
      cin >> S;
      if (S<0 || S>1000)
        exit (2);
      sum += S;
      if (largest < S)
        largest=S;
      if (smallest > S)
      smallest=S;
    }
    int average = 0;
    average = (sum - largest - smallest) / (N - 2);
    cout << average << endl;
  }
}
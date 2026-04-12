#include <iostream>
using namespace std;
int N,S;
int main() {
 while (cin >> N && N>0) {
  int max = 0;
  int min = 1000;
  int sum = 0;
  int answer;
  for (int i=0; i<N; ++i) {
   cin >> S;
   sum += S;
   if(max < S) max = S;
   if(min > S) min = S;
  }
  answer = (int)((sum-max-min)/(N-2));
  cout << answer << endl;
 }
}
  

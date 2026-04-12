#include <iostream>

using namespace std;

int main(void){
  string S;
  cin >> S;

  int count_A = 0, count_B = 0;
  for(int i=0; i<3; i++){
    if(S[i] == 'A')
      count_A++;
    else if(S[i] == 'B')
      count_B++;
  }

  if(count_A>0 && count_B>0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    
  return 0;
}

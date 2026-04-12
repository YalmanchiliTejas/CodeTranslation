#include <iostream>
using namespace std;
string S;
int main(){
  cin >> S;
  int N = S.size();
  for(int i=0;i<N-1;i++){
    if(S[i]=='A' && S[i+1]=='C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
string S;
cin >> S;
int K;
cin >> K;
for(int i=0;i<N;i++){
  if(S.substr(K-1,1) != S.substr(i,1)){
    S.replace(i, 1, "*");
  }
}
cout << S << endl;
}

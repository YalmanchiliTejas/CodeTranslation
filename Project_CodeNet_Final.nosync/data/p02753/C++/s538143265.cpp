#include <iostream>
#include <string>

using namespace std;

int abs(int num){
  if(num >= 0){
    return num;
  }else{
    return -num;
  }
}

int main(){
  string S;
  cin >> S;
  int sum=0;
  for(int i=0;i<2;i++){
    sum += abs(S[i+1] - S[i]);
  }

  if(sum > 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;

}

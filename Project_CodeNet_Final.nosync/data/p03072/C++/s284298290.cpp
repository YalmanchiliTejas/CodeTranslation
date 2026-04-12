#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int H[n];
  for(int i = 0;i < n;i++){
    cin >> H[i];
  }
  int first = H[0];
  int count = 1;
  for(int i = 1;i < n;i++){
    if(first <= H[i]){
      count++;
      first = H[i];
    }
  }
  cout << count << endl;
}

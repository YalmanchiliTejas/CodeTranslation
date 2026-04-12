#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  int h[n];
  for(int i = 0; n > i; i++)cin>>h[i];
  int cansee = 1;
  int canshe = h[0];
  for(int i = 1; n > i; i++){
    if(canshe <= h[i]){
      cansee++;
      canshe = h[i];
    }
  }
  cout << cansee << endl;
}
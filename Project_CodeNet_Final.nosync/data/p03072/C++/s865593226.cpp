#include<iostream>
using namespace std;
int main(){
  int n,h;
  int max=0,count=0;
  cin >> n;
  
    while(n--){
    cin >> h;
    if(max<=h){
      max = h;
      count++;
    }
  }
  cout << count << endl;
  return 0;
  
}
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int back = n/15;
  cout << 800*n - 200*back << endl;
} 

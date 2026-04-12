#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
  int n;
  int cou = 1;
  cin >> n;
  vector<int> A(n,0);

  for(int i = 0;i < n;i++){
    cin >> A[i];
  }

  for(int j = 1;j < n;j++){
    int l = 0;
    if(A[j-1] <= A[j]){
      for(int k = 0;k < j;k++){if(A[k]<=A[j]){l++;}}
      if(l == j){cou++;}
  }
  }

  cout << cou << endl;
  return 0;
  }

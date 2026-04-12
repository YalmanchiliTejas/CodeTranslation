#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> mt(n);
  vector<int> maxmt(n);
  for (int i=0; i<n; i++){
    cin >> mt[i];
  }
  maxmt[0]=mt[0];
  for (int i=1; i<n; i++){
    maxmt[i]=max(maxmt[i-1], mt[i]);
  }
  int c=0;
  for (int i=0; i<n; i++){
    if (mt[i] == maxmt[i]){
      c++;
    }
  }
  cout << c;
}
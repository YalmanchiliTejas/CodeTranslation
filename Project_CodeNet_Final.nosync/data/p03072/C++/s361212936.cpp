#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int H[n];
  for (int i= 0; i<n; i++) {
  	cin >> H[i];
  }
  int count = 1;
  for (int i = 1; i<n; i++) {
    for (int j = 0; j<i; j++) {
    	if (H[j]>H[i]) break;
      	if (j == i-1) count++;
    }
  }
  cout << count << endl;
}
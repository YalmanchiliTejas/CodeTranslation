#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, s[100];
  int sam = 0, ave[100];
  int min, max;
  int kmin = 0, kmax = 0;
  int k = 0;
  
  while(true){
    cin >> n;
    if(n == 0) break;
    sam = 0;
    
    for(int i = 0; i < n; ++i){
      cin >> s[i];
      sam += s[i];

      if(i == 0){
	min = s[i];
	max = s[i];
      }
      
      if(min > s[i]) min = s[i];
      if(max < s[i]) max = s[i];

      if(min == s[i] && kmin == 0) ++kmin;
      if(max == s[i] && kmax == 0) ++kmax;
    }
    ave[k] = (sam - min - max) / (n - kmin - kmax);
    ++k;
  }

  for(int f = 0; f < k; ++f){
    cout << ave[f] << endl;
  }
  
    
  return 0;
}


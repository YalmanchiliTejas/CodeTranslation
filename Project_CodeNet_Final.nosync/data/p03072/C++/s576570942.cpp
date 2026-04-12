#include <bits/stdc++.h>
using namespace std;

int n, maxi=0, res=0, tmp;

int main(){
  cin >> n;
  for(int i=1; i<=n; ++i){
    cin >> tmp;
    if (tmp>=maxi){
      res++;
      maxi=tmp;
    }
  }
  cout << res;
  return 0;
}
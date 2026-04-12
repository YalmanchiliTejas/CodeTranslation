#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,res=0,max=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a;
    if(max<=a){
      res++;
      max=a;
    }
  }
  cout << res << endl;
}

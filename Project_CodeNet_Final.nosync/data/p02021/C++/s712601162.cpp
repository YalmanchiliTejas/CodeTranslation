#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[110];
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  for(int i = 1;i <= 110;i++){
    int work = 0;
    for(int j = 0;j < n;j++){
      work += a[j];
      work -= i;
      if(work < 0){
        cout << i-1 << endl;
        return 0;
      }
    }
  }

  return 0;
}


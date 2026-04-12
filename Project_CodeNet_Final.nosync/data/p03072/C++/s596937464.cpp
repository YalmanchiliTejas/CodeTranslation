#include<iostream>
#include<vector>

using namespace std;

int main(){
 int n; cin >> n;
  int count = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    bool is_highest = true;
    for (int k = 0;k<i;k++){
      if (a[i] < a[k]){
        is_highest = false;
        break;
      }
    }
    if (!is_highest){
      continue;
    }
    count++;
  }
  
  cout << count << endl;
  
  return 0;
}
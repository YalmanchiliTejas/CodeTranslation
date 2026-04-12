#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> h(n);
  for(int i = 1;i <= n;i++){
    cin >> h[i];
  }
  int max = 0;
  int count = 0;
  for(int i = 1;i <= n;i++){
    if(h[i] >= max){
      max = h[i];
      count++;
    }
  }
  cout << count << endl;
}
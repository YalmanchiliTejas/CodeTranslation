#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> bars;
  for(int i=0;i<12;i++){
    int temp;
    cin >> temp;
    bars.push_back(temp);
  }
  sort(bars.begin(),bars.end());
  bool isyes = true;
  for(int i=0;i<3;i++){
    if(bars[0+4*i]!=bars[1+4*i] || bars[0+4*i]!=bars[2+4*i] || bars[0+4*i]!=bars[3+4*i]){
      isyes = false;
    }
  }
  if(isyes)cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}

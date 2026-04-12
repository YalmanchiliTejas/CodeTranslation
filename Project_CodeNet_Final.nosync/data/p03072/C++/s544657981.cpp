#include <iostream>
#include <vector>
using namespace std;
int main(){
  int k, temp;
  int max = 0;
  int count = 0;
  vector<int> mheight;
  cin >> k;
  for(int i=0; i<k; i++){
    cin >> temp;
    mheight.push_back(temp);
  }
  for(int j=0; j<k; j++){
    if(mheight[j] >= max){
      max = mheight[j];
      count++;
    }
  }
  cout << count << endl;
  return 0;
}

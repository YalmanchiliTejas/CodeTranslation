#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void remove_minmax(vector<int> &data){
  int max = 0;
  int min = 1000000;
  int min_i = 0;
  int max_i = 0;
  int count = 0;
  vector<int>::iterator it = data.begin();
  while (it != data.end()){
    if (*it < min){
      min = *it;
      min_i = count;
    }
    if (*it > max){
      max = *it;
      max_i = count;
    }
    ++count;
    ++it;
  }
  data[max_i] = 0;
  data[min_i] = 0;
}

int main(void){
  int n;
  while (cin >> n){
    if (n == 0){
      return 0;
    }
    
    vector<int> data;
    
    for (int i=0; i<n; ++i){
      int num;
      cin >> num;
      data.push_back(num);
    }
    remove_minmax(data);

    int total = floor((double)accumulate(data.begin(), data.end(), 0)/(n-2));
    cout << total << endl;
  }
  return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0;i < N;i++) {
    cin >> vec.at(i);
  }
  int count = 1;
  int Max = vec.at(0);
  for(int j = 1;j < N;j++) {
    if(Max == vec.at(j)) {
      count++;
    }
    else if(Max < vec.at(j)) {
      Max = vec.at(j);
      count++;
    }
  }
  cout << count << endl;
}
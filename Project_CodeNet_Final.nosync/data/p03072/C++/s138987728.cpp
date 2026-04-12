#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> data(N);
  int max_num;
  int counter = 1;
  for(int i =0;i < N;i++){
    cin >> data[i];
  }

  max_num = data[0];

  for(int i = 1;i < N;i++){
    if(data[i] >= max_num)counter++;
    max_num = max(max_num,data[i]);
  }

  cout << counter << endl;
}
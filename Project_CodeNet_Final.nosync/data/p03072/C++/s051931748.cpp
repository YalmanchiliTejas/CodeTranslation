#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, H;
  cin >> N;
  vector<int> height(N);
  for (int i=0; i<N; i++){
    cin >> height.at(i);
  }
  int ht;
  int hotel = 0;
  for (int i=0; i<N; i++){
    ht = height.at(i);
    sort(height.begin(),height.begin() + (i+1));
    //cout << ht << height.at(i);
    if (ht == height.at(i)) hotel++;
    else continue;
  }
  cout << hotel << endl; 
}
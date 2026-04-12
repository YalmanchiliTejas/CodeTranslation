#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin >> N;
vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
int j = 1;
int k = vec.at(0);
int count = 1;
while(N > j){
  if(k <= vec.at(j)){
  count++;
  k = vec.at(j);
  }
j++;
}
cout << count << endl;
}

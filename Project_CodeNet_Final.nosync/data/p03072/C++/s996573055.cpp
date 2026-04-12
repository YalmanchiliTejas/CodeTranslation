#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  int i;
  for(i=0;i<n;i++){
    cin >> vec.at(i);
  }
  int count=1,maxi=vec.at(0);
  for(i=1;i<n;i++){
    if(maxi<=vec.at(i)){
      maxi=vec.at(i);
      count++;
    }
  }
  cout << count;
}
      